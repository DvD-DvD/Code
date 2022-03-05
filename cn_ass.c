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

char ext[] = " HTTP/1.1\r\nHost: ";
char http_port[] = ":443";
char escape[] = "\r\n";
char proxy_auth = "Proxy-Authorization: Basic ";
char colon = ":";
char proxy_credentials[500] = "";

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


// bool send_request(char request[],char *superString){
// 	bool temp = false;
// 	send(socket,http_request,strlen(http_request),0);
// 	int bytes_recieved = 0;
// 	char buffer[1000000];
// 	int total_bytes = 0;
// 	while((bytes_recieved = recv(socket,buffer,(sizeof(buffer)-1),0)) > 0){
//         buffer[bytes_recieved] = 0;
//         total_bytes += bytes_recieved;
//         printf("%s",buffer);
//         strcat(superString,buffer);
//     }
//     bool redirection = false;

//     if(buffer[9] == '3' && buffer[10] == '0'){
//         redirection = true;
//         printf("Redirected to HTTPS\n");
//     }

//     bool red_to_http;
//     if(redirection){
//     	char redirected_url[1000];
//     	for(int i=0;i<strlen(superString);i++){
//     		if(superString[i] == 'L' && superString[i+1] == 'o' && superString[i+2] == 'c'){
//     			int j = i+10;
//     			if(superString[i+14] == 's'){
//     				red_to_http = false;
//     			}
//     			else{
//     				red_to_http = true; 
//     			}
//     			int itr = 0;
//     			while(superString[j] != '\n'){
//     				url[itr++] = superString[j++];
//     			}
//     			break;
//     		}
//     	}
//     }
//     if(!redirection){
//     	printf("%s\n",superString);
//     }
//     else{
//     	if(!red_to_http){
//     		temp = true;
//     	}
//     	else{
//     		char new_host[1000];
//     		for(int i=0;i<strlen(url);i++){
//     			if(url[i] == ':' && url[i+1] == '/' && url[i+2] == '/)'{
//     				int itr = 0;
//     				for(int j = i+2;(url[j] != '/' && url[j] != '\r');j++){
//     					new_host[itr++] = url[j];
//     				}
//     			}
//     		}
//     		memset(request,0,sizeof(request));
    		
//     		strcat(request,"GET ")
//     		strcat(request,url);
// 		    strcat(request,ext);
// 		    strcat(request,new_host);
// 		    strcat(request,escape);
// 		    strcat(request,proxy_auth); 
// 		    strcat(request,encoded_cred);
// 		    strcat(request,escape);
// 		    strcat(request,"Accept: */*");
// 		    strcat(request,escape);
// 		    strcat(request,"Proxy-Connection: Keep Alive");
// 		    strcat(request,escape);
// 		    strcat(request,"Connection: Close");
// 		    strcat(request,escape);
// 		    strcat(request,escape);

// 		    memset(superString,0,sizeof(superString));

// 		   	temp = send_request(request,superString,socket);
//     	}
//     }
//     return temp;

// }


void image_url_scrape(char http_response[],char *image_url){
    int length = strlen(http_response);
    for(int i=0;i<length;i++){
        if(http_response[i] == 'i' && http_response[i+1] == 'm' && http_response[i+2] == 'g'){
            i += 9;
            while(http_response[i] != '"'){
                image_url[itr++] = http_response[i++];
            }
            printf("image url is: %s\n",image_url);
            return;
        }
    }

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
        FILE* logo_file = fopen(logo_path,"a");
    }


/////////////////////////////////////////////////////////////////////Forming HTTP request with user input/////////////////////////////////////
            
    char http_request[1000] = "GET http://";
   

    //Forming proxy cred to send into base64 encoder
    strcat(proxy_credentials,server_username);
    strcat(proxy_credentials,colon);
    strcat(proxy_credentials,server_password);
    char *encoded_cred = base64Encoder(proxy_credentials,strlen(proxy_credentials));

    // concatenating http request
    strcat(http_request,host_name);
    strcat(http_request,ext);
    strcat(http_request,host_name);
    strcat(http_request,escape);
    strcat(http_request,proxy_auth); 
    strcat(http_request,encoded_cred);
    strcat(http_request,escape);
    strcat(http_request,"Accept: */*");
    strcat(http_request,escape);
    strcat(http_request,"Proxy-Connection: Keep Alive");
    strcat(http_request,escape);
    strcat(http_request,"Connection: Close");
    strcat(http_request,escape);
    strcat(http_request,escape);

    printf("HTTP Request with Proxy%s\n",http_request);

///////////////////////////////////////////////////////////// Setting up proxy and Making a connection///////////////////////////////////////
    struct sockaddr_in proxy;
    proxy.sin_family = AF_INET;
    proxy.sin_addr.s_addr = inet_addr(server_ip);
    proxy.sin_port = htons(port_number);

    //HTTP socket creation and making a coonection 
    int socket = socket(AF_INET,SOCK_STREAM,0);
    connect(socket,(struct sockadd *)&proxy,sizeof(proxy));
    printf("Socket coonection established\n");
    
    // Sending HTTP request through socket
    send(socket,http_request,strlen(http_request),0);
    printf("GET Reuest sent\n");



    // Receive HTTP Response and check for https redirection
    bool https_redirection = false;
    bool itr = false; 
    int bytes_recieved = 0;
    int total_bytes = 0;
    char http_response[1000000];
    char buffer[1000000];

    while((bytes_recieved = recv(socket,buffer,(sizeof(buffer)-1),0)) > 0){
        if(itr == false){
            if(buffer[9] == '3' && buffer[10]){
                https_redirection = true;
                printf("Redirected to HTTPS\n");
                break;
            }
        }

        buffer[bytes_recieved] = 0;
        total_bytes += bytes_recieved;
        printf("%s",buffer);
        strcat(http_response,buffer);
        itr = true;
    }
    ////write to file
    close(socket);              //  close socket

    // scrape logo url from http response
    char image_url[1000] = "";
    image_url_scrape(http_response,image_url);


}


	char ext[] = " HTTP/1.1\r\nHost: ";
	char http_port[] = ":443";
	char escape[] = "\r\n";
	char proxy_auth = "Proxy-Authorization: Basic ";
	char colon = ":";
	char proxy_credentials[500] = "";

 	strcat(http_request,host_name);
    strcat(http_request,ext);
    strcat(http_request,host_name);
    strcat(http_request,escape);
    strcat(http_request,proxy_auth); 
    strcat(http_request,encoded_cred);
    strcat(http_request,escape);
    strcat(http_request,"Accept: */*");
    strcat(http_request,escape);
    strcat(http_request,"Proxy-Connection: Keep Alive");
    strcat(http_request,escape);
    strcat(http_request,"Connection: Close");
    strcat(http_request,escape);
    strcat(http_request,escape);

    printf("HTTP Request with Proxy%s\n",http_request);

    struct sockaddr_in proxy;
    proxy.sin_family = AF_INET;
    proxy.sin_addr.s_addr = inet_addr(server_ip);
    proxy.sin_port = htons(port_number);
    int socket = socket(AF_INET,SOCK_STREAM,0);
    connect(socket,(struct sockadd *)&proxy,sizeof(proxy));
   
 
   
    send(socket,http_request,strlen(http_request),0);
    printf("GET Reuest sent\n");

    bool https_redirection = false;
    bool itr = false; 
    int bytes_recieved = 0;
    int total_bytes = 0;
    char http_response[1000000];
    char buffer[1000000];

    while((bytes_recieved = recv(socket,buffer,(sizeof(buffer)-1),0)) > 0){
        if(itr == false){
            if(buffer[9] == '3' && buffer[10]){
                https_redirection = true;
                printf("Redirected to HTTPS\n");
                break;
            }
        }

        buffer[bytes_recieved] = 0;
        total_bytes += bytes_recieved;
        printf("%s",buffer);
        strcat(http_response,buffer);
        //call fwrite 
        itr = true;
    }
    close(socket);  