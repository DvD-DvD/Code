#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 10005

int no_of_files = 0, flag, length_inp, length_file;
char input[MAX_N], file_names[MAX_N][MAX_N], read_permissions[MAX_N], input[MAX_N], c;

int in_same_file(int file_id)
{
    length_file = strlen(file_names[file_id]);
    if(length_file != length_inp)
        return 0;
    for(int i = 0; i < length_inp; i++)
    {
        if(file_names[file_id][i] != input[i])
            return 0;
    }
    return 1;
}

int match_extension(int file_id)
{
    if(strstr(file_names[file_id], input) != NULL) {
        return 1;
    }
    return 0;
    
}

int match_directory(int file_id)
{
    if(strstr(file_names[file_id], input) != NULL) {
        return 1;
    }
    return 0;
    
}

int match_name(int file_id)
{
    if(strstr(file_names[file_id], input) != NULL) {
        return 1;
    }
    return 0;
    
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", input);
        scanf("%s", file_names[no_of_files]);
        read_permissions[no_of_files] = (input[0] == 'r' && input[1] == '-' && input[2] == '-') ? 'Y' : 'N';
        no_of_files++;
    }

    int q;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%s%c", input, &c);
        if(input[0] == 'l')
        {
            if(c == '\n')
            {
                for(int i = 0; i < no_of_files; i++)
                    printf("%s\n", file_names[i]);
            }
            else
            {
                scanf("%s", input);
                length_inp = strlen(input);
                for(int i = 0; i < no_of_files; i++)
                    if(match_directory(i))
                        printf("%s\n", file_names[i]);
            }
        }
        else if(input[0] == 'a')
        {
            scanf("%s", file_names[no_of_files]);
            read_permissions[no_of_files] = 'Y';
            no_of_files++;
        }
        else if(input[0] == 'c')
        {
            int d;
            scanf("%d", &d);
            scanf("%s", input);
            length_inp = strlen(input);
            for(int i = 0; i < no_of_files; i++)
                if(in_same_file(i))
                    read_permissions[i] = (d == 4) ? 'Y' : 'N';
        }
        else if(input[0] == 'r')
        {
            if(c == '\n')
            {
                for(int i = 0; i < no_of_files; i++)
                    if(read_permissions[i] == 'Y')
                        printf("%s\n", file_names[i]);
            }
            else
            {
                scanf("%s", input);
                length_inp = strlen(input);
                for(int i = 0; i < no_of_files; i++)
                    if(read_permissions[i] == 'Y' && match_directory(i))
                        printf("%s\n", file_names[i]);
            }
        }
        else
        {
            scanf("%s", input);
            length_inp = strlen(input);
            if(input[0] == '.')
            {
                for(int i = 0; i < no_of_files; i++)
                    if(match_extension(i))
                        printf("%s\n", file_names[i]);
            }
            else
            {
                for(int i = 0; i < no_of_files; i++)
                    if(match_directory(i) || match_name(i))
                        printf("%s\n", file_names[i]);
            }
        }
    }
} 