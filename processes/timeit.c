#include <stdio.h>
#include <time.h>

int main(){
    time_t now;
    struct tm *local;

    now = time(NULL);
    local = localtime(&now);

    if (local == NULL){
        printf("Error getting current time.\n");
        return 1;
    }

    printf("Local time: %02d-%02d-%04d %02d:%02d:%02d\n",
        local->tm_mday,
        local->tm_mon + 1,
        local->tm_year + 1900,
        local->tm_hour,
        local->tm_min,
        local->tm_sec
    );

    return 0;
}