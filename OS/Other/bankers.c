#include<stdio.h>

#define MP 10
#define MR 10

int safe(int max[MP][MR], int alloc[MP][MR], int avail[MR],int p, int r);

void main()
{
  int p,r;
  printf("Enter the number of processes:\n");
  scanf("%d", &p);

  printf("Enter the number of resources:\n");
  scanf("%d", &r);  
  
  int max[MP][MR], alloc[MP][MR], avail[MR];
  printf("Enter the maximum needed resources for\n");
  for(int i=0;i<p;i++)
  {
    printf("for process p%d:\n",i);
    for(int j=0;j<r;j++)
      scanf("%d", &max[i][j]);
  }

  printf("Enter the already allocated resources for\n");
  for(int i=0;i<p;i++)
  {
    printf("for process p%d:\n",i);
    for(int j=0;j<r;j++)
      scanf("%d", &alloc[i][j]);
  }
  
  printf("Enter the available resources\n");
  for(int j=0;j<r;j++)
      scanf("%d", &avail[j]);
  
  if(safe(max,alloc,avail,p,r))
    printf("The System is in safe state and no Deadlock can be detected\n");
  else
    printf("The System is in unsafe state and Deadlock is detected\n");    
    
}
  
int safe(int max[MP][MR], int alloc[MP][MR], int avail[MR],int p, int r)
{
  int check[MP];
  for(int i=0;i<p;i++)
    check[i]=0;
    
  int work[MR];
  for(int i=0;i<r;i++)
    work[i]= avail[i];
    
  int count=0;
  
  while(count<p)
  {
    int found=0;
    for(int i=0;i<p;i++)
    {
      int canallocate=1;
      
      if(check[i]!=0)
        continue;
        
      for(int j=0;j<r;j++)
      {
        if(max[i][j]-alloc[i][j]> work[j])
          {
            canallocate=0;
            break;
          }
        }
        
      if(canallocate)
      {
        for(int j=0;j<r;j++)
          work[j]+=alloc[i][j];
        check[i]=1;
        count++;
        found=1;
      }
    }
    if(found==0)
      return 0;
  }
    return 1;
}
        
    
        
