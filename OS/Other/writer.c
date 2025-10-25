#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>


int main()
{
  key_t key= ftok("shmfile", 65);
  int shmid= shmget(key, 1024, IPC_CREAT | 0666);
  char *shm= (char *)shmat(shmid,NULL,0);
  
  printf("Write data\n:");
  fgets(shm,1024,stdin);
  
  shmdt(shm);
  
  return 0;
}

  
  
