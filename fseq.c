#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct file 
{
  char filename[200];
  int start;
  int no;
};

void fconfig( struct file* file1, int start, int count)
{ 
  strcpy((*file1).filename,"file.txt");
  (*file1).start= start;
  (*file1).no= count;
}

void main()
{
  struct file file1;
  int a1,a2;

  printf("Enter the starting block:");
  scanf("%d", &a1);
  
  printf("Enter the number of blocks: ");
  scanf("%d", &a2);
  
  fconfig(&file1,a1,a2);
  
  printf("File Name: %s\n", file1.filename);
  printf("Start Block: %d\n", file1.start);
  printf("Number of Blocks: %d\n", file1.no);
}



