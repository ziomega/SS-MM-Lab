#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

#define SIZE 5

sem_t full;
sem_t empty;

pthread_mutex_t mutex;

int buffer[SIZE];
int in=0;
int out=0;

void* consumer(void* arg);
void* producer(void* arg);

int main()
{
  sem_init(&full,0,0);
  sem_init(&empty,0,SIZE);
  
  pthread_mutex_init(&mutex, NULL);

  pthread_t cthread, pthread;
  pthread_create(&cthread, NULL, consumer, NULL);
  pthread_create(&pthread, NULL, producer, NULL);
  
  pthread_join(pthread, NULL);
  pthread_join(cthread, NULL);
  
  sem_destroy(&empty);
  sem_destroy(&full);
  pthread_mutex_destroy(&mutex);
  
  return 0;
}

void* consumer(void* arg)
{
  while(1)
  {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    
    int item= buffer[out];
    printf("%d removed\n", item);
    out= (out+1)%SIZE;
    
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    sleep(2);
  }
}

void* producer(void* arg)
{
  while(1)
  {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    
    int item= rand()%100;
    buffer[in]=item;
    printf("%d added\n", item);
    in= (in+1)%SIZE;
    
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    sleep(1);
  }
}


    
