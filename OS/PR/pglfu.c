#include<stdio.h>
#include<stdlib.h>


void lfu(int pages[], int p, int frames[], int f);
int replacer(int frames[], int freq[], int f);

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
  
  lfu(pages,p,frames,f);
  
}

void lfu(int pages[], int p, int frames[], int f)
{
  int faults=0;
  int freq[f];
  
  for(int i=0;i<f;i++)
    freq[i]=0;
  
  printf("Frame contents\n");
  for(int i=0;i<p;i++)
  {
    int found=0;
    int page= pages[i];
    
    for(int j=0;j<f;j++)
    {
      if(frames[j]==page)
      {
        found=1;
        freq[j]++;
        break;
      }
    }
    
    if(found==0)
    {
      faults++;
      
      int empty=-1;
      for(int j=0;j<f;j++)
      {
        if(frames[j]==-1)
        {
          empty=j;
          break;
        }
      }
      
      if(empty!=-1)
      {
        frames[empty]= page;
        freq[empty]=1;
      }
      
      else
      {
        int replace= replacer(frames,freq,f);
        frames[replace]= page;
        freq[replace]=1;
      }
    }
      for(int j=0;j<f;j++)
        printf("%d\t", frames[j]);
     
      if(found==0)
        printf("Page Fault\n");
        
      else 
        printf("Hit\n");
  }
  printf("No of page faults: %d\n", faults);
}

int replacer(int frames[], int freq[], int f)
{
  int index=0;
  int minF= freq[0];
  
  for(int i=1;i<f;i++)
  {
    if(freq[i]<minF)
    {
      minF= freq[i];
      index=i;
    }
  }
  return index;
}

