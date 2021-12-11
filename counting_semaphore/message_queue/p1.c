#include<stdio.h>
#include <sys/mman.h>
       #include <sys/stat.h>        /* For mode constants */
       #include <fcntl.h>  
        #include <mqueue.h>
mqd_t message;
struct mq_attr message_attr;
int main(int argc , char const *argv[]){
message_attr.mq_flags=0;
message_attr.mq_maxmsg=4;
message_attr.mq_msgsize=128;
message_attr.mq_curmsgs=0;
message=mq_open("/message", O_WRONLY |
O_CREAT ,S_IRUSR,S_IWUSR,&message_attr);
mq_send(message ,  "aditya\n", 6, 0);
mq_close(message);
return 0;
}
