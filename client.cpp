#include <stdio.h>
#include "hysocket.h"
#include "command.h"
void* rec(void* s)
{
    HySocketBase * b = (HySocketBase*)s;

    while(1)
    {
        int len = 0;
        b->recv(&len , 4);
        char buf[128] = {0};
        b->recv_all(buf, len);
        printf("\n>> :%s\n", buf);
    }

}

void sendCommand(HySocketClient * cl, int cmd)
{
    cl->send(&cmd, 4);
}

void recvAck(HySocketClient * cl)
{
    int buf = 0;
    cl->send(&buf, 4);

    printf("ACK = %x\n", buf);
}

const int commands[] = 
{
    0xffffffff,
    0x31000000,
    0x32000000,
    0x30000002,
    0x30000003,
    0x30000004,
    0x30000005,
    0x30000006,
    0x30000007,
    0x30000008,
    0x30000009,
    0x3000000a,
    0x3000000b,
    0x3000000c,
    0x3000000d,
    0x3000000f,
    0x30000011,
    0x30000012,
    0x30000013,
    0x30000014,
    0x30000015,
    0x30000016,
    0x30000017,
    0x30000018,
    0x30000019,
    0x3000001a,
    0x3000001b
};

int main(int argc, const char * argv[])
{
    HySocketClient * cl = new HySocketClient;
    //cl->connect("192.168.11.101", 20000);
    cl->connect("127.0.0.1", 20000);
    //cl->connect("172.20.10.15", 20000);
    //cl->connect("172.20.10.15", 20000);

    // pthread_t p;
    // pthread_create(&p, NULL, rec, cl);

#if 1
    sendCommand(cl, MAGIC_KEY);
    recvAck(cl);

    while (1)
    {
        int cmd = 0;
        printf("input command :\n");
        scanf("%d", &cmd);
        printf("your input %x\n", commands[cmd]);

        int real_cmd = commands[cmd];

        cl->send_all(&real_cmd, 4);
        recvAck(cl);

    }
#endif

//    while (1)
//    {
        // char buf[128];
        // printf("Me:");
        // scanf("%[^\n]s", buf);
        // getchar();
        // int len = strlen(buf);
        // int ret = cl->send_all(&len, 4);
        // ret = cl->send_all(buf, len);
//    }
    return 0;
}
