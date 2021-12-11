#include<stdio.h>
 #include <fcntl.h>           /* For O_* constants */
       #include <sys/stat.h>        /* For mode constants */
       #include <mqueue.h>
mqd_t message;
struct mq_attr message_attr;
char buff [128];
int msg_prio;
int main(int argc , char const *argv[]){
    message_attr.mq_flags=0;
message_attr.mq_maxmsg=4;
message_attr.mq_msgsize=128;
message_attr.mq_curmsgs=0;
message =mq_open("/message", O_RDONLY | O_CREAT,S_IRUSR | S_IWUSR,&message_attr);
mq_receive(message,buff, 128,&msg_prio);
printf("received message: %s\nMsg_prio:%d\n",buff , msg_prio);
mq_close(message);
return 0;

}