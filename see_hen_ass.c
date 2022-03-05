#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<openssl.ssl.h>

#define size 1000

char* base64Encoder(char input_str[], int len_str) 
{  
    char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/:"; 
    char *res_str = (char *) malloc(size * sizeof(char));   
    int index, no_of_bits = 0, padding = 0, val = 0, count = 0, temp; 
    int i, j, k = 0;  
    for (i = 0; i < len_str; i += 3){ 
            val = 0, count = 0, no_of_bits = 0; 
  
            for (j = i; j < len_str && j <= i + 2; j++){  
                val = val << 8;   
                val = val | input_str[j];  
                count++; 
              
            } 
  
            no_of_bits = count * 8;   
            padding = no_of_bits % 3;  
            while (no_of_bits != 0){  
                if (no_of_bits >= 6){ 
                    temp = no_of_bits - 6;  
                    index = (val >> temp) & 63;  
                    no_of_bits -= 6;          
                } 
                else{ 
                    temp = 6 - no_of_bits; 
                    index = (val << temp) & 63;  
                    no_of_bits = 0; 
                } 
                res_str[k++] = char_set[index]; 
            } 
    }
    for (i = 1; i <= padding; i++){ 
        res_str[k++] = '='; 
    } 
  
    res_str[k] = '\0'; 
  
    return res_str; 
  
}


int main(int argc, char *argv[]){
	// taking input from command line
    char *host_name = argv[1];
    char *server_ip = argv[2];
    int port_number = atoi(argv[3]);
    char *server_username = argv[4];
    char *server_password = argv[5];
    char *cmd_html = argv[6];

    char html_path[1000] = "./";
    strcat(html_path,html_file);
    FILE* html_file = fopen(html_path,"w");

    char *cmd_logo;
    if(argc==8){
        cmd_logo = argv[7];
        char logo_path[100] = "./";
        strcat(logo_path,cmd_logo);
        FILE* logo_file = fopen(logo_path,"w");
    }


/////////////////////////////////////////////////////////////////////Forming HTTP request with user input/////////////////////////////////////
            
    char http_request[1000] = "GET http://";
    char ext[] = " HTTP/1.1\r\nHost: ";
    char http_port[] = ":443";
    char escape[] = "\r\n";
    char proxy_auth = "Proxy-Authorization: Basic ";
    char colon = ":";
    char proxy_credentials[500] = "";

    //Forming proxy cred to send into base64 encoder
    strcat(proxy_credentials,server_username);
    strcat(proxy_credentials,colon);
    strcat(proxy_credentials,server_password);
    char *encoded+cred = base64Encoder(proxy_credentials,strlen(proxy_credentials));

    // concatenating http request
    strcat(http_request,host_name);
    strcat(http_request,ext);
    strcat(http_request,host_name);
    strcat(http_request,escape);
    strcat(http_request,proxy_auth); 
    //strcat(http_request,encoded_cred);
    // strcat(http_request,escape);
    // strcat(http_request,"Accept: */*");
    // strcat(http_request,escape);
    // strcat(http_request,"Proxy-Connection: Keep Alive");
    // strcat(http_request,escape);
    // strcat(http_request,"Connection: Close");
    // strcat(http_request,escape);
    // strcat(http_request,escape);

    printf("HTTP Request with Proxy%s\n",http_request);

///////////////////////////////////////////////////////////// Setting up proxy and Making a connection///////////////////////////////////////
    struct sockaddr_in proxy;
    proxy.sin_family = AF_INET;
    proxy.sin_addr.s_addr = inet_addr(server_ip);
    proxy.sin_port = htons(port_number);

}