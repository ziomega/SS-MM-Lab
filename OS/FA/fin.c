	#include <stdio.h>
#include <stdlib.h>

struct Index 
{
    int blocks[100];
};

void initialize(struct Index *index) 
{
    for (int i = 0; i < 100; i++) {
        index->blocks[i] = -1;
    }
}

int isAllocated(struct Index *index, int no) 
{
    for (int i = 0; i < 100; i++) {
        if (index->blocks[i] == no) {
            return 1;
        }
    }
    return 0;
}

int allocate(struct Index *index, int no) 
{
    for (int i = 0; i < 100; i++) {
        if (index->blocks[i] == -1) {
            index->blocks[i] = no;
            return 1;
        }
    }
    return 0;
}

void read(struct Index *index, int no) 
{
    int flag = 0;
    for (int i = 0; i < 100; i++) {
        if (index->blocks[i] != -1 && no == index->blocks[i]) {
            printf("Reading from block %d\n", index->blocks[i]);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("Block %d not allocated.\n", no);
}

int main() 
{
    struct Index index;
    int n, no;

    initialize(&index);

    printf("Enter number of blocks to allocate: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No blocks to allocate.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) 
    {
        printf("Enter block number to allocate (%d/%d): ", i + 1, n);
        scanf("%d", &no);

        if (no < 0 || no >= 100) 
        {
            printf("Invalid block number. Block numbers must be between 0–99.\n");
            continue;
        }

        if (isAllocated(&index, no)) 
        {
            printf("Block %d already allocated. Try a different block.\n", no);
            continue;
        }

        if (!allocate(&index, no)) 
        {
            printf("Failed to allocate block %d. Index table full.\n", no);
            break;
        } 
        
        else 
        {
            printf("Block %d allocated successfully.\n", no);
        }
    }

    printf("\nAllocated Blocks: ");
    
    for (int i = 0; i < 100; i++) 
    {
        if (index.blocks[i] != -1) 
        {
            printf("%d ", index.blocks[i]);
        }
    }
    printf("\n");

    while (1) 
    {
        printf("\nEnter block number to read (or -1 to exit): ");
        scanf("%d", &no);

        if (no == -1)
            break;

        read(&index, no);
    }

    printf("Program terminated.\n");
    return 0;
}

