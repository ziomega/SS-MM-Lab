#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct block 
{
    int no;
    struct block *next;
};

struct block* allocate(int no) 
{
    struct block* block1 = (struct block*) malloc(sizeof(struct block));
    block1->no = no;
    block1->next = NULL;
    return block1;
}

int isAllocated(int disk[], int size, int no) 
{
    if (no < 0 || no >= size)
        return -1;
    return disk[no];
}

int main() 
{
    int n, no, totalBlocks;
    int disk[100] = {0}; 
    struct block* head = NULL;
    struct block* current = NULL;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &totalBlocks);

    printf("Enter the number of blocks to allocate: ");
    scanf("%d", &n);

    if (n <= 0) 
    {
        printf("No blocks to allocate.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) 
    {
        printf("Enter the block number %d: ", i + 1);
        scanf("%d", &no);

        int status = isAllocated(disk, totalBlocks, no);

        if (status == -1) {
            printf(" Invalid block number (%d). Skipping.\n", no);
            continue;
        } 
        else if (status == 1) {
            printf(" Block %d is already allocated. Skipping.\n", no);
            continue;
        }

        struct block* newBlock = allocate(no);

        if (head == NULL)
            head = current = newBlock;
        else {
            current->next = newBlock;
            current = current->next;
        }

        disk[no] = 1;
        printf("Block %d allocated successfully.\n", no);
    }

    printf("\nAllocated blocks (linked list): ");
    current = head;
    if (current == NULL) {
        printf("None\n");
    } else {
        while (current != NULL) {
            printf("%d", current->no);
            if (current->next != NULL) printf(" -> ");
            current = current->next;
        }
        printf("\n");
    }

    current = head;
    while (current != NULL) {
        struct block* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

