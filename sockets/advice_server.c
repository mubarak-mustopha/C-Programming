#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

void error(char *msg){
    fprintf(stderr, "%s: %s\n", msg,strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    char *advice[] = {
        "Take smaller bites\r\n",
        "Go for the baggy jeans. No they do NOT make you look ugly.\r\n",
        "One word: inappropriate\r\n",
        "Just for today, be honest. Tell your boss what you *really* think\r\n",
        "You might want to rethink that haircut\r\n"
    };

    int listener_d = socket(PF_INET, SOCK_STREAM, 0);

    int reuse = 1;
    if (setsockopt(listener_d,SOL_SOCKET,SO_REUSEADDR, (char *) &reuse, sizeof(int)) == -1)
        error("Can't set the reuse option on the socket");


    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listener_d, (struct sockaddr *) &name, sizeof(name)) == -1)
        error("Can't bind port");

    if (listen(listener_d, 10) == -1)
        error("Can't listen");
    puts("Waiting for connection");

    while (1){
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
        if (connect_d == -1)
            error("Can't open secondary socket");
        char *msg = advice[rand() % 5];

        if (send(connect_d, msg, strlen(msg), 0) == -1)
            error("send");
        close(connect_d);
    }

    return 0;
}