#include <stdio.h>
#include <stdlib.h>

void cscan(int req[], int n, int head, int size, int direction);

void main()
{
      int req[100], n, head, size;
      int direction;
      
      printf("Enter number of requests:\n");
      scanf("%d", &n);
      
      printf("Enter the request sequence:\n");
      for(int i=0;i<n;i++)
	  scanf("%d", &req[i]);
	  
      printf("Enter head position:\n");
      scanf("%d", &head);
      
      printf("Enter direction(0 for left,1 for right):\n");
      scanf("%d", &direction);
      
      printf("Enter disk size:\n");
      scanf("%d", &size);
        
      cscan(req,n,head,size,direction);
}


void cscan(int req[], int n, int head, int size, int direction)
{
  int totalseek=0;
  int left[100];
  int right[100];
  int l=0;
  int r=0;
  
  for(int i=0;i<n;i++)
  {
    if(req[i]>head)
      right[r++]=req[i];
      
    else
      left[l++]= req[i];
  }
  
  if(direction==0)
    left[l++]=0;
  else
    right[r++]=size-1;
    
  
  for(int i=0;i<l;i++)
  {
    for(int j=i+1;j<l;j++)
    {
      if(left[i]>left[j])
      {
        int temp= left[i];
        left[i]= left[j];
        left[j]= temp;
      }
    }
  }

  for(int i=0;i<r;i++)
  {
    for(int j=i+1;j<r;j++)
    {
      if(right[i]>right[j])
      {
        int temp= right[i];
        right[i]= right[j];
        right[j]= temp;
      }
    }
  }
  
  printf("Seek order: %d->", head);
  if(direction==0)
  {
    for(int i=l-1;i>=0;i--)
    {
      printf("%d->", left[i]);
      totalseek+= abs(head- left[i]);
      head=left[i];
    }
    
    printf("%d->", size-1);
    totalseek+=abs(head-(size-1));
    head=0;
    
    for(int i=r-1;i>=0;i--)
    {
      printf("%d->", right[i]);
      totalseek+= abs(head- right[i]);
      head=right[i];
    }
  }

  if(direction==1)  
  {
    for(int i=0;i<r;i++)
    {
      printf("%d->", right[i]);
      totalseek+= abs(head- right[i]);
      head=right[i];
    }
    
    printf("0->");
    totalseek+=abs(head-0);
    head=0;
    
    for(int i=0;i<l;i++)
    {
      printf("%d->", left[i]);
      totalseek+= abs(head- left[i]);
      head=left[i];
    }
  }
  
  printf("\nSeek time :%d\n", totalseek);
}


    
  
  
      


  
    

      
      


