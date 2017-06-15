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
    0x30000001,
    0x30000002,
    0x30000004,
    0x30000008,
    0x30000010,
    0x30000020,
    0x30000040,
    0x30000080,
    0x30000100,
    0x30000200,
    0x30000400,
    0x30000800,
    0x30001000,
    0x30002000,
    0x30004000,
    0x30008000,
    0x30010000,
    0x30020000,
    0x30040000,
    0x30080000,
    0x30100000,
    0x30200000,
    0x30400000,
    0x30800000,
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
