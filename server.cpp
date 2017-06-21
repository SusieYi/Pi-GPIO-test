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


int cmd_parser(int cmd , int type)
{

    char buf[4] = {0};
    char * p = buf;
    *(int*)p = cmd;

    printf("cmd%x\n",cmd);
    printf("%x %x %x %x\n",p[0],p[1],p[2],p[3]);
    switch (type)
    {
        case 1:
            return p[3] >> 4;
            break;
        case 2:
            return p[3] & 0x0f;
            break;
        case 3:
            {
            int gpio;
            return p[0];
            //printf("debug gpio%d\n",gpio);
            return gpio;
            }
            break;
        default:
            return 0;
            break;
    }

}




int main(int argc, const char * argv[])
{
    HySocketServer * s = new HySocketServer;
    s->setup("0.0.0.0", 20000);
    HySocketClient * cl = s->accept();
    // pthread_t p;
    // pthread_create(&p, NULL, rec, cl);



#if 1
    int cmd;
    cl->recv_all(&cmd,4);
    printf("%x\n",cmd);
    

    int ack = 0x11111111;
    cl->send_all(&ack,4);

    while(1)
    {
        cl->recv_all(&cmd,4);
        //    printf("%x\n",cmd);
        int interface_class = cmd_parser(cmd,1);
        printf("class%x\n",interface_class);
        if(interface_class == 3)
        {
            int interface_setup = cmd_parser(cmd ,2);
            int gpio = cmd_parser(cmd,3);
            printf("GPIO MODE\n");
            printf("GPIO:%x setup:%x\n",gpio,interface_setup);
        }
    else
    {
        printf("cmd error!\n");
    }
        cl->send_all(&ack,4);

       // * cmd = 
       //
       // do-command by recived command
       //
       //  *send(ack)


    }



    return 0;
#endif

//    while (1)
//    {
        char buf[128] = {0};
       // scanf("%[^\n]s", buf);
       // getchar();
        int len = 0;
  //      cl->recv_all(&len, 4);
        printf("%d\n",len);
        cl->recv_all(buf, 3);
        printf("%s\n",buf); 
        // int ret = 0;
        // ret = cl->send_all(&len, 4);
        // ret = cl->send_all(buf, len);
//    }
    return 0;
}
