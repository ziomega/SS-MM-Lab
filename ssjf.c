#include<stdio.h>
#include<stdbool.h>

struct Process
{
  int id;
  int at;
  int bt;
  int ct;
  int wt;
  int tat;
  bool done;
};


void main()
{
  int n;
  printf("Enter the number of process:\n");
  scanf("%d", &n);
  
  struct Process process[n];
  
  for(int i=0;i<n;i++)
  {
    printf("Enter the AT and BT for Process%d:\n", i+1);
    scanf("%d %d", &process[i].at, &process[i].bt);
    process[i].id= i+1;
    process[i].done= false;
  }
  
  struct Process gantt[n];
  int gidx=0;
  
  int completed=0;
  int currenttime=0;
  int totalwt=0;
  int totaltat=0;
  
  while(completed<n)
  {
    int idx= -1; 
    int minBT= 1000;
    //min burst time give a big burst time for initialisation
  //idx for selected process to schedule 
  
  for(int i=0;i<n;i++)
  {
    if(process[i].at<=currenttime && !process[i].done && process[i].bt<minBT)
    {
      minBT= process[i].bt;
      idx=i;
    }
  }
  if(idx==-1)
  {
    currenttime++;
    continue;
  }
  
  process[idx].ct= currenttime+ process[idx].bt;
  process[idx].tat= process[idx].ct- process[idx].at;
  process[idx].wt= process[idx].tat -  process[idx].bt;
  
  totaltat+= process[idx].tat;
  totalwt+= process[idx].wt;
  
  currenttime= process[idx].ct;
  process[idx].done= true;
  gantt[gidx]= process[idx];
  gidx++;
  completed++;
}

printf("\n%-6s %-6s %-6s %-6s %-6s %-6s\n", "PID", "AT", "BT", "CT", "WT", "TAT");

for(int i=0;i<n;i++)
{
  printf("P%-5d %-6d %-6d %-6d %-6d %-6d\n", process[i].id, process[i].at, process[i].bt, process[i].ct, process[i].wt, process[i].tat);
}

printf("\n Gantt Chart\n");

const int width= 7;
for(int i=0;i<gidx;i++)
{
  for(int j=0;j<width;j++)
    printf("-");
  printf(" ");
}

printf("\n");

  for(int i=0;i<gidx;i++)
  {
    int spaces= width-2;
    int left= spaces/2;
    int right= spaces- left;
    printf("%*sP%d%*s|",left,"",gantt[i].id,right,"");
  }
  
printf("\n");
for(int i=0;i<n;i++)
{
  for(int j=0;j<width;j++)
    printf("-");
  printf(" ");
}

printf("\n");
printf("%-2d", gantt[0].at);
for(int i=0;i<gidx;i++)
{
  printf("%*d", width, gantt[i].ct);
}
}
    
    
    
    
    
    
  
  

