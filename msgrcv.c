#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msg_buffer
{
long msg_type;
char msg[100];
}
message;
void main()
{
key_t my_key;
int msg_id;
my_key=ftok("progfile",65);
msg_id=msgget(my_key,0666|IPC_CREAT);
msgrcv(msg_id,&message,sizeof(message),1,0);
printf("recieved message is:%s\n",message.msg);
msgctl(msg_id,IPC_RMID,NULL);
}

