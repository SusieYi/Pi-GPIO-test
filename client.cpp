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

    //printf("ACK = %x\n", buf);
}

const int commands[] = 
{
    0x02000001,
    0x80000004,
    0x00000000
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
   // sendCommand(cl, MAGIC_KEY);
   // recvAck(cl);

    while (1)
    {
        int cmd = 0;
        printf("input command :\n");
        scanf("%d", &cmd);
        printf("your input %x\n", commands[cmd]);

        int real_cmd = commands[cmd];
        int ack = 0;
        cl->send_all(&real_cmd, 4);
        cl->recv_all(&ack,4);

        printf("ack %x\n",ack);

        char buf[4] = {0};
        char *p = buf;
        *(int*)p = ack;
        int val = 0;

        for(int i=0 ; i<4 ; i++)
        {
            val+=p[i];
        }
        if(val!= 1)
        {
        printf("no ack!\n");
        break;
        }

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
