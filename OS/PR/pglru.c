#include <stdio.h>
#include <stdlib.h>

void LRU(int pages[], int n, int frames[], int f);
int replacer(int pages[], int frames[], int n, int f, int current);

int main() {
    int n, f;

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    int frames[f];
    for (int i = 0; i < f; i++)
        frames[i] = -1;

    printf("Enter the number of pages in reference string: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    LRU(pages, n, frames, f);
    return 0;
}

void LRU(int pages[], int n, int frames[], int f)
{
	int faults=0;
	
	for(int i=0;i<n;i++)
	{
		int page=pages[i];
		int found=0;
		for(int j=0;j<f;j++)
		{
			if(frames[j]==page)
			{
				printf("Page already in frame\n");
				found=1;
				break;
			}
		}
		if(found!=1)
		{
			faults++;
			int empty=-1;
			for(int k=0;k<f;k++)
			{
				if(frames[k]==-1)
				{
					empty=k; 
					break;
				}
			}
			if(empty==-1)
			{
				int replace=replacer(pages,frames, n, f, i);
				frames[replace]=page;
			}
			else
			{
				frames[empty]=page;
			}
		}
		for(int i=0;i<f;i++)
                  printf("%d \t",frames[i]);
      
                if(found==0)
                  printf("Page Fault\n");
        
                else 
                  printf("Hit\n");
	}
	
	printf("Final Frames: ");
	for (int i = 0; i < f; i++) {
	    if (frames[i] == -1)
		printf("-\t");
	    else
		printf("%d\t", frames[i]);
	}
	printf("\nTotal Page Faults: %d\n", faults);

}

int replacer(int pages[], int frames[], int n, int f, int current)
{
	int leastrecent=current;
	int index =-1;
	
	for(int i=0;i<f;i++)
	{
		int j;
		for(j=current-1;j>=0;j--)
		{
			if(frames[i]==pages[j])
			{
				if(j<leastrecent)
				{
					leastrecent=j;
					index=i;
				}
				break;
			}
		}
		if(j==-1)
			return i;
	}
	if(index==-1)
		return 0;
	else 
		return index;
}		
		
