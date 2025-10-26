#include<stdio.h>

void firstFit(int blocks[], int b, int processes[], int p);

int main() 
{
    int b, p;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &b);
    int blocks[b];

    printf("Enter the sizes of the %d memory blocks:\n", b);
    for (int i = 0; i < b; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &p);
    int processes[p];

    printf("Enter the sizes of the %d processes:\n", p);
    for (int i = 0; i < p; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processes[i]);
    }

    firstFit(blocks, b, processes, p);

    return 0;
}
void firstFit(int blocks[], int b, int processes[], int p)
{
	int allocation[p];
	for(int i=0;i<p;i++)
		allocation[i]=-1;
	
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(blocks[j]>=processes[i])
			{
				allocation[i]=j;
				blocks[j]-= processes[i];
				break;
			}
		}
	}
	
	for(int i=0;i<p;i++)
	{
		printf("Process no:%d\n Process size: %d \nAllocated Block: %d\n\n", i+1,processes[i], allocation[i]+1);
	}
}
	
