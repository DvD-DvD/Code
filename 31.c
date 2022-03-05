#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <pthread.h>

typedef struct thread_data
{
    char * a;
    char * b;
    int result;

} thread_data;

void *myThread(void *arg)
{
    thread_data *tdata=(thread_data *)arg;
    if(strstr(tdata->a,tdata->b) != NULL)
    {
        tdata->result++;
    }
   pthread_exit(NULL);
}

typedef struct file_t
{
    char absPath[10000];
    char owner[10000];
    char group[10000];
} file_t; 

char * getcpy(char * name)
{
    char * nm = (char *) malloc(strlen(name)*sizeof(char));
    nm = strcpy(nm,name);
    return nm;
}

file_t * newFile(char * absPath, char * owner,char * group)
{
    file_t * newfile = (file_t *) malloc(sizeof(file_t));
    strcpy(newfile->absPath,absPath);
    strcpy(newfile->owner,owner);
    strcpy(newfile->group,group);
    return newfile;
}

int SZ = 0;
file_t * files[100];
char inp[100][10000];

void print(file_t * file)
{
    printf("%s %s %s\n",file->owner,file->group,file->absPath);
}

int main()
{
    int n;
    scanf(" %d ",&n);
    for(int i =0;i<n;i++)
    {
        scanf(" %[^\n]s ",inp[i]);
        char *cpy = getcpy(inp[i]);
        char *token = strtok(cpy," ");
        char *owner = getcpy(token);
        token = strtok(NULL," ");
        char *group = getcpy(token);
        token = strtok(NULL," ");
        char *absPath = getcpy(token);
        files[SZ++] = newFile(absPath,owner,group);
    }

    int q;
    scanf(" %d ",&q);
    char query[10000];
    for(int i = 0;i<q;i++)
    {
        scanf(" %[^\n]s ",query);
        for(int j = 0;j<SZ;j++)
        {
            int flag = 0;
            thread_data t1,t2,t3,t4;
            t1.a = files[j]->absPath;
            t2.a = files[j]->owner;
            t3.a = files[j]->group;
            t4.a = inp[j];
            t1.b = query;
            t2.b = query;
            t3.b = query;
            t4.b = query;
            t1.result = 0;
            t2.result = 0;
            t3.result = 0;
            t4.result = 0;
            pthread_t pth[4];
            pthread_create(&pth[0],NULL,myThread,(void *)&t1);
            pthread_create(&pth[1],NULL,myThread,(void *)&t2);
            pthread_create(&pth[2],NULL,myThread,(void *)&t3);
            pthread_create(&pth[3],NULL,myThread,(void *)&t4);
            pthread_join(pth[0],NULL);
            pthread_join(pth[1],NULL);
            pthread_join(pth[2],NULL);
            pthread_join(pth[3],NULL);
            if(t1.result + t2.result + t3.result + t4.result> 0)
            {
                printf("%s\n",inp[j]);
            }
        }
    }
}