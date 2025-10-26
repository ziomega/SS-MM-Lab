#include <stdio.h>
#include <stdlib.h>

void Optimal(int pages[], int n, int frames[], int f);
int replacer(int pages[], int n, int frames[], int f, int current);

int main() 
{

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
	
	Optimal(pages, n, frames, f);
	return 0;
}

void Optimal(int pages[], int n, int frames[], int f)
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
				printf("Page is loaded\n");
				found=1;
				break;
			}

		}
		if(found==0)
		{
			printf("Loaded from memory\n");
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
				frames[empty]=page;
			else
			{
			int replace= replacer(pages,n,frames,f,i);
			frames[replace]=page;
			}
		}
	for(int i=0;i<f;i++)
          printf("%d \t",frames[i]);
      
        if(found==0)
          printf("Page Fault\n");
        
        else 
          printf("Hit\n");
          
	}
	
	printf("Frames: ");
        for (int k = 0; k < f; k++) {
            if (frames[k] == -1)
                printf("-\t");
            else
                printf("%d\t", frames[k]);
        }
        printf("\n");	
        printf("Number of page faults: %d\n", faults);
}

int replacer(int pages[], int n, int frames[], int f, int current)
{
	int index=-1;
	int farthest=current;
	for(int i=0;i<f;i++)
	{
		int j;
		for(j=current+1;j<n;j++)
		{
			if(frames[i]==pages[j])
			{
				if(j>farthest)
				{
					farthest=j;
					index=i;
				}
				break;
			}
		}
	if(j==n)
		return i;
	}
	
	if(index==-1)
		return 0;
	else 
		return index;
}

	


