#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void error(char *msg){
    fprintf(stderr, "%s: %s", msg,strerror(errno));
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

    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(listener_d, (struct sockaddr *) &name, sizeof(name));

    while (1){
        if (listen(listener_d, 10) == -1)
            error("Can't listen");
        puts("Waiting for connection");

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