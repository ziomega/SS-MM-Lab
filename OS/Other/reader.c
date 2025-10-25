#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>


int main()
{
  key_t key= ftok("shmfile",65);
  int shmid= shmget(key,1024,0666);
  char* shm= (char*)shmat(shmid, NULL,0);
  
  printf("Message from Writer\n");
  printf("%s",shm);
  
  shmdt(shm);
  shmctl(shmid, IPC_RMID,NULL);
  
  return 0;
}

