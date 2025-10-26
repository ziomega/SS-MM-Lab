#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct file
{
    char filename[50];
    int start;
    int no;
    int allocated;
};

int main()
{
  
    struct file files[50];
    int n;
    int disk[100] = {0};
    int totalBlocks;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &totalBlocks);

    printf("Enter number of files to add: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("\nEnter file name: ");
        scanf("%s", files[i].filename);

        printf("Enter starting block: ");
        scanf("%d", &files[i].start);

        printf("Enter number of blocks: ");
        scanf("%d", &files[i].no);

        int flag = 0; 

        for (int j = files[i].start; j < (files[i].start + files[i].no); j++)
        {
            if (j >= totalBlocks || disk[j] == 1)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0) 
        {
            for (j = files[i].start; j < (files[i].start + files[i].no); j++)
                disk[j] = 1;
                
            files[i].allocated = 1;
            printf("File '%s' allocated successfully.\n", files[i].filename);
        } 
        else 
        {
            files[i].allocated = -1;
            printf("File '%s' cannot be allocated (Block %d already in use or out of range).\n", files[i].filename, j);
        }
    }

    printf("\n\nFile Allocation Table:\n");
    printf("------------------------------------------------------\n");
    printf("File Name\tStart Block\tNo. of Blocks\tStatus\n");
    printf("------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        if (files[i].allocated)
            printf("%-10s\t%-12d\t%-13d\tAllocated\n", files[i].filename, files[i].start, files[i].no);
        else
            printf("%-10s\t%-12d\t%-13d\tNot Allocated\n", files[i].filename, files[i].start, files[i].no);
    }

    printf("------------------------------------------------------\n");
    return 0;
}

