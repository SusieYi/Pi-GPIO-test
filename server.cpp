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

int main(int argc, const char * argv[])
{
    HySocketServer * s = new HySocketServer;
    s->setup("0.0.0.0", 20000);
    HySocketClient * cl = s->accept();
    // pthread_t p;
    // pthread_create(&p, NULL, rec, cl);



#if 1

    // recv magic key
    //  send(ack)

    while(1)
    {
       * cmd = read

       do-command by recived command

        *send(ack)


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
