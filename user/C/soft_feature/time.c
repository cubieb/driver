#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


static void getTheCurrentTime(char *time_now)
{
    time_t now;
    struct tm *timenow;

    time(&now);
    timenow = localtime(&now);
    snprintf(time_now, 32, "%d%02d%02d%02d%02d%02d", timenow->tm_year + 1900, timenow->tm_mon + 1, timenow->tm_mday,
             timenow->tm_hour, timenow->tm_min, timenow->tm_sec);
}



int main()
{
    char *str = NULL;
    getTheCurrentTime(str);
    printf("%s\n", str);
    return 0;
}




