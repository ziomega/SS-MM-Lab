#include<stdio.h>

struct Process
{
  int id;
  int at;
  int bt;
  int ct;
  int tat;
  int wt;
  int rt;
};

void main()
{
  int n, tq;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  
  struct Process p[n];
  for (int i = 0; i < n; i++) 
  {
    p[i].id = i + 1;
    printf("Enter AT and BT for Process P%d: ", i + 1);
    scanf("%d %d", &p[i].at, &p[i].bt);
    
    p[i].rt = p[i].bt;
  }
  
  printf("Enter Time Quantum: ");
  scanf("%d", &tq);
  
  int currenttime=0;
  int completed=0;
  
  int size=0;
  
  int totaltat=0;
  int totalwt=0;
  
  struct 
  {
    int pid;
    int start;
    int end;
  }gantt[100];
  
  while(completed<n)
  {
    int executed=0;
    
    for(int i=0;i<n;i++)
    {
      if(p[i].rt>0 && p[i].at<= currenttime)
      {
        executed=1;
        gantt[size].pid= p[i].id;
        gantt[size].start= currenttime;
        
        if(p[i].rt <= tq)
        {
          currenttime += p[i].rt;
          p[i].rt=0;
          
          gantt[size].end= currenttime;
          size++;

          p[i].ct= currenttime;
          p[i].tat= p[i].ct - p[i].at;
          p[i].wt= p[i].tat- p[i].bt;
          completed++;
        }
        
        else
        {
        currenttime += tq;
        p[i].rt-= tq;
        gantt[size].end= currenttime;
        size++;
        }
      }
    }
    if(!executed)
      currenttime++;
    }
    
printf("\n %-6s %-6s %-6s %-6s %-6s %-6s\n", "PID", "AT", "BT", "CT", "TAT", "WT");
for(int i=0;i<n;i++)
{
  printf(" P%-5d %-6d %-6d %-6d %-6d %-6d\n",p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
  
}
printf("\nGantt Chart:\n\n");
const int width = 7;

for (int i=0; i<size; i++) {
    for (int j=0; j<width; j++)
          printf("-");
    printf(" ");
}
printf("\n");
for(int i=0;i<size;i++)
{ 
  int spaces=width-2;
  int left= spaces/2;
  int right= spaces/2 +1;
  printf("%*sP%d%*s|", left,"", gantt[i].pid, right,"");
}

printf("\n");
for (int i=0; i<size; i++) {
    for (int j=0; j<width; j++)
          printf("-");
    printf(" ");
}

printf("\n");
printf("%-2d", gantt[0].start);
for (int i=0; i <size; i++) {
    printf("%*d", width+1, gantt[i].end);
}
}

    
    
    
        
    

