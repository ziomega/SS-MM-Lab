#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Index
{
  int blocks[100];
};

void initialize(struct Index *index)
{
  for(int i=0;i<100;i++)
  {
    index->blocks[i]=-1;
  }
}

int allocate(struct Index *index, int no)
{
  for(int i=0;i<100;i++)
  {
    if(index->blocks[i]==-1)
    { 
     index->blocks[i]=no;
     return 1;
    }
    
  }
  return 0;
  
}

void read(struct Index *index, int no)
{
  int flag=0;
  for(int i=0;i<100;i++)
  {
    if(index->blocks[i]!=-1 && no==index->blocks[i])
    {
      printf("Read from block %d\n", index->blocks[i]);
      flag=1;
      break;
    }
  }
  if(flag==0) 
    printf("Block not allocated.\n");
}

void main() 
{
    struct Index index;
    int n, no;

    initialize(&index);
  printf("Enter number of blocks to allocate: ");
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    printf("Enter block number to allocate (%d/%d): ", i + 1, n);
    scanf("%d", &no);

    if (!allocate(&index, no)) {
        printf("Failed to allocate block %d. Index block might be full.\n", no);
    }
}

printf("\nAllocated Blocks: ");
for (int i = 0; i < 100; i++) {
    if (index.blocks[i] != -1) {
        printf("%d ", index.blocks[i]);
    }
}
printf("\n");

while (1) {
    printf("\nEnter block number to read (or -1 to exit): ");
    scanf("%d", &no);
    
    if (no == -1) break;
    read(&index, no);
}

}


