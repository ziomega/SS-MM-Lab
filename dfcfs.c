#include<stdio.h>
#include<stdlib.h>

int main()
{
  int req[100], n, head;
  int totalseek=0;
  
  printf("Enter the number of requests:\n");
  scanf("%d", &n);
  
  if(n>100 || n<=0)
  {
    printf("Invalid no of Requests\n");
    return 0;
  }
  
  printf("Enter the requests:\n");
  for(int i=0;i<n;i++)
    scanf("%d", &req[i]);

  printf("Enter the head position:\n");
  scanf("%d", &head);
  
  for(int i=0;i<n;i++) 
  {
    totalseek+= abs(head-req[i]);
    head= req[i];
  }
  
  printf("Total Seek :%d\n", totalseek);
}
  
