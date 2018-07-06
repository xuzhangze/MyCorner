#include <stdio.h>
#include <mysql.h>

int main()
{
    MYSQL* sql = mysql_init(NULL);
    if(mysql_real_connect(sql, "127.0.0.1", "root", "cjmxzz1314", "student", 0, NULL, 0) == 0)
    {
        printf("mysql_real_connect\n");
        exit(1);
    }
    
    const char* p = "select * from tt1";
    mysql_query(sql, p);

    MYSQL_RES* result = mysql_store_result(sql);

    int row = mysql_num_rows(result);
    int col = mysql_num_fields(result);
    //printf("row:%d  col:%d\n", row, col);    //测试
    MYSQL_FIELD* field = mysql_fetch_fields(result);
    int i = 0;
    printf("<h3>");
    for(; i < col; ++i)
        printf("%s\t", field[i].name);
    printf("</h3>");
    MYSQL_ROW line;
    for(i = 0; i < row; ++i)
    {
        printf("<h3>");
        line = mysql_fetch_row(result);
        int j = 0;
        for(; j < col; ++j)
        {
            printf("%s\t", line[j]);
        }
        printf("</h3>");
    }

    mysql_close(sql);
    free(result);
    return 0;
}
