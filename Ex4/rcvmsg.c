#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <sys/ipc.h>

#define MAX 20

struct m_buf
{
 long m_type;
 char m_text[300];
} msg;

int main()
{
  key_t key;
  int x;
  
  key = ftok("code4life",25);
  x = msgget(key, 0666 | IPC_CREAT);
  
  msgrcv(x , &msg , sizeof(msg) , 1, 0);
  printf("Message Received: %s \n", msg.m_text);
  msgctl(x, IPC_RMID, NULL);
  
  return 0;
}
  
