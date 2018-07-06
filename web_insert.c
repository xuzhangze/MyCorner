#include <stdio.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>


void Insert(int id, char* name, int age)
{
    char command[128] = {};
    MYSQL* sql = mysql_init(NULL);
    if(!mysql_real_connect(sql, "127.0.0.1", "root", "cjmxzz1314", "student", 0, NULL, 0))
    {
        printf("connect faild\n");
        exit(1);
    }
    sprintf(command, "insert into tt1 values(%d,\"%s\",%d)", id, name, age);
    printf("%s\n", command);
    mysql_query(sql, command);
    //printf("OK\n");
    //
    mysql_close(sql);
}

int main()
{
    char method[16] = {};
    char parameter[1024] = {};
    int id = 0;
    char name[20] = {};
    int age = 0;
    strcpy(method, getenv("METHOD"));
    if(strcasecmp(method, "GET") == 0)
    {
        strcpy(parameter, getenv("PARAMETER"));
    }
    else if(strcasecmp(method, "POST") == 0)
    {
        int i = 0;
        char ch;
        int content_length = atoi(getenv("CONTENT_LENGTH"));
        for(; i < content_length; ++i)
        {
            read(0, &ch, 1);
            parameter[i] = ch;
        }
        parameter[i] = 0;
    }
    else
    {
        printf("method error\n");
    }

    //id=xxx&name=xxx&age=xxx
   // strcpy(parameter, "id=000&name=xiaoming&age=22");
    strtok(parameter, "=&");
    id = atoi(strtok(NULL, "=&"));
    strtok(NULL, "=&");
    strcpy(name, strtok(NULL, "=&"));
    strtok(NULL, "=&");
    age = atoi(strtok(NULL, "=&"));
    printf("id:%d  name:%s age:%d\n", id, name, age);


    Insert(id, name, age);

    return 0;
}
