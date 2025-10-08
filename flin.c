#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct block
{
  int no;
  struct block *next;
};

struct block* allocate(int no)
{
  struct block* block1= (struct block*) malloc(sizeof(struct block));
  block1->no= no;
  block1->next=NULL;
  return block1;
}

void main()
{
  int n,no;
  struct block* head= NULL;
  struct block* current= NULL;  
  
  printf("Enter the number of blocks to allocate:\n");
  scanf("%d", &n);

  if (n <= 0) 
  {
    printf("No blocks to allocate.\n");
    return;
  }
  
  for(int i=0;i<n;i++)
  {
    printf("Enter the block number %d:\n",i+1);
    scanf("%d", &no);
    
    struct block* new= allocate(no);
    
    if(head==NULL)
    {
      head= new;
      current= head;
    }
    
    else
    {
      current->next= new;
      current= current->next;
    }
  }
    
    printf("Allocated blocks:");
    current= head;
    while(current!=NULL)
    {
      printf("%d", current->no);
      current= current->next;
    }
    printf("\n");
    
    current = head;
    while (current != NULL)
    {
    struct block* temp = current;
    current = current->next;
    free(temp);
    }
  
}
