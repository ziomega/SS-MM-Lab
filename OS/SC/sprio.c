#include<stdio.h>
#include<stdbool.h>

struct Process
{
  int id;
  int pr;
  int at;
  int bt;
  int ct;
  int tat;
  int wt;
  bool done;
  
};

void main()
{
  int n;
  printf("Enter the number of Processes:\n");
  scanf("%d", &n);
  
  struct Process p[n];
  
  for(int i=0;i<n;i++)
  {
    p[i].id=i+1;
    
    printf("Enter the AT, BT and priority of the process P%d: \n", i+1);
    scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr);
    p[i].done=false;
    
  }
  //sort based on arrival time and burst time 
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(p[i].at> p[j].at || (p[i].at== p[j].at && p[i].bt> p[j].bt))
      {
        struct Process temp= p[i];
        p[i]= p[j];
        p[j]= temp;
      }
    }
  }
  
  int currenttime=0;
  int totaltat=0;
  int totalwt=0;
  int completed=0;
  
  struct Process gantt[n];
  int gidx=0;
  
  while(completed<n)
  {
    int idx=-1;
    int minPr= 1000;
    for(int i=0;i<n;i++)
    {
      if(p[i].at<=currenttime && !p[i].done && p[i].pr< minPr)
      {
        minPr= p[i].pr;
        idx=i;
      }
    }
    
    if(idx==-1)
    {
      currenttime++;
      continue;
    }
    

    p[idx].ct = currenttime + p[idx].bt;
    p[idx].tat= p[idx].ct- p[idx].at;
    p[idx].wt= p[idx].tat- p[idx].bt;
    
    totalwt+= p[idx].wt;
    totaltat+=p[idx].tat;

    currenttime = p[idx].ct;    
    p[idx].done=true;
    completed++;
    gantt[gidx]= p[idx];
    gidx++;
  }
  
  printf("\n%-6s %-6s %-6s %-6s %-6s %-6s %-6s\n", "PID", "PR", "AT", "BT", "CT", "TAT", "WT");
  
  for(int i=0;i<n;i++)
  {
    printf("P%-5d %-6d %-6d %-6d %-6d %-6d %-6d\n", p[i].id, p[i].pr, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    
}

printf("\n Gantt Chart\n");

const int width= 7;

for(int i=0;i<gidx;i++)
{
  for(int i=0;i<width;i++)
    printf("-");
  printf(" ");
}

printf("\n");
for(int i=0;i<gidx;i++)
{
  int spaces=width-2;
  int left= spaces/2;
  int right= spaces- left;
  
  printf("%*sP%d%*s|", left,"", gantt[i].id, right,"");
}

printf("\n");
for(int i=0;i<gidx;i++)
{
  for(int i=0;i<width;i++)
    printf("-");
  printf(" ");
}

printf("\n");
printf("%-2d", gantt[0].at);
for(int i=0;i<gidx;i++)
{
  printf("%*d",width, gantt[i].ct);
}
}
