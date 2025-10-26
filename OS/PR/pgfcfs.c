#include<stdio.h>
#include<stdlib.h>


void fcfs(int pages[], int p, int frames[], int f);


void main()
{
  int p,f;
  printf("Enter the number of frames\n");
  scanf("%d", &f);
  printf("Enter the number of pages\n");
  scanf("%d", &p); 
  
  int pages[p];
  int frames[f];
  
  printf("Enter the page reference string\n"); 
  for(int i=0;i<p;i++)
    scanf("%d", &pages[i]);
  
for(int i=0;i<f;i++)
  frames[i]=-1;
  
  fcfs(pages,p,frames,f);
  
}

void fcfs(int pages[], int p, int frames[], int f)
{
  int faults=0;
  int index=0;
  
  printf("Frame contents\n");
  
  for(int i=0;i<p;i++)
  {
    int page= pages[i];
    
    int found=0;
    for(int j=0;j<f;j++)
    {
      if(frames[j]==page)
      {
        found=1;
        break;
      }
    }
    
    if(found==0)
    {
      faults++;
      frames[index]= page;
      index= (index+1)%f;
    }
    for(int i=0;i<f;i++)
      printf("%d \t",frames[i]);
      
      if(found==0)
        printf("Page Fault\n");
        
      else 
        printf("Hit\n");
        
  }

}      
    
    
  
