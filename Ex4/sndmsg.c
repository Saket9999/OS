#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <sys/ipc.h>

#define MAX 20

struct m_buf
{
	long m_type;
	char m_txt[300];
} msg;

int main()
{
  key_t key;
  int x;
  
  key = ftok("code4life", 65);
  x = msgget(key, 0666 | IPC_CREAT);
  
  msg.m_type = 1;
  printf("Pass the message");
  
  fgets(msg.m_txt,MAX,stdin);
  msgsnd(x, &msg, sizeof(msg),0);
  printf("Message is: %s \n", msg.m_txt);
  
  return 0;
}
  
