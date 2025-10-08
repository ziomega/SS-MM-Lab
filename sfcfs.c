#include<stdio.h>

struct Process
{
  int id;
  int at;
  int bt;
  int ct;
  int tat;
  int wt;
  
};

int main()
{
  int n;
  printf("Enter the number of Processes:\n");
  scanf("%d", &n);
  
  struct Process process[n];
  
  for(int i=0;i<n;i++)
  {
    process[i].id=i+1;
    
    printf("Enter the AT and BT of the process P%d: \n", i+1);
    scanf("%d %d", &process[i].at, &process[i].bt);
    
  }
  
  for(int i=0;i<n;i++)
  {
    //ith position gets its correct element at each pass
    for(int j=i+1;j<n;j++)
    {
      if(process[i].at>process[j].at)
      {
        struct Process temp= process[i];
        process[i]= process[j];
        process[j]= temp;
      }
    }
  }
  
  int currenttime=0;
  int totalwt=0;
  int totaltat=0;
  
  for(int i=0;i<n;i++)
  {
    if(currenttime<process[i].at)
      currenttime= process[i].at;
      
    currenttime += process[i].bt;
    process[i].ct= currenttime;
    
    process[i].tat= process[i].ct- process[i].at;
    process[i].wt= process[i].tat- process[i].bt;  
    
    totalwt+= process[i].wt;
    totaltat+= process[i].tat;   
    
  }
  // %-xd: x width is used for that 
printf("\n%-6s %-6s %-6s %-6s %-6s %-6s\n", "PID", "AT", "BT", "CT", "TAT", "WT");
  
  for(int i=0;i<n;i++)
  {
    printf("P%-5d %-6d %-6d %-6d %-6d %-6d\n",i+1, process[i].at,process[i].bt, process[i].ct, process[i].tat, process[i].wt);
  }
  
  printf("The average waiting time and turn around time is %d and %d respectively\n", totalwt/n, totaltat/n);
  
printf("\n Gantt Chart \n");

const int width=7;

for(int i=0;i<n;i++)
{
  for(int j=0;j<width;j++)
    printf("-");
  printf(" ");
}


printf("\n");
for(int i=0;i<n;i++)
{
  int spaces= width-2;//-2 for p1, p2 etc
  int left= spaces/2;//dividing remaining space equally 
  int right= spaces- left;
  
  printf("%*sP%d%*s|", left, "", process[i].id, right,"");
}
// %*s for leaving space before a character (width of space, character)

printf("\n");
for(int i=0;i<n;i++)
{
  for(int j=0;j<width;j++)
    printf("-");
  printf(" ");
}

printf("\n");
int time=0;
printf("%-2d", time);

for(int i=0;i<n;i++)
{
  if(time<process[i].at)
    time= process[i].at;
    
  time+= process[i].bt;
  printf("%*d", width, time);
}
printf("\n");
}
    
