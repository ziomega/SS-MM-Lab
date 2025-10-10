#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    FILE *fp;
    int i, j, staddr1;
    char name[10], line[50], name1[10], staddr[10], filename[50];

    printf("Enter program name: ");
    scanf("%s", name);

    printf("Enter object file name (with extension): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("Error: Unable to open file '%s'.\n", filename);
        exit(1);
    }

    fscanf(fp, "%s", line);
    if (line[0] != 'H') 
    {
        printf("Error: Invalid object program format.\n");
        fclose(fp);
        return;
    }

    for (i = 2, j = 0; i < 8 && j < 6; i++, j++)
        name1[j] = line[i];
    name1[j] = '\0';

    printf("\nProgram name from object file: %s\n", name1);


    if (strcmp(name, name1) == 0) 
    {
        printf("\n--- Loading Program into Memory ---\n\n");

        while (fscanf(fp, "%s", line) != EOF) 
        {
            if (line[0] == 'T') 
            {
                for (i = 2, j = 0; i < 8 && j < 6; i++, j++)
                    staddr[j] = line[i];
                staddr[j] = '\0';

                staddr1 = (int)strtol(staddr, NULL, 16);

                i = 12; 
          
                while (line[i] != '$' && line[i] != '\0') 
                {
                    if (line[i] != '^') {
                        printf("00%04X\t%c%c\n", staddr1, line[i], line[i + 1]);
                        staddr1++;
                        i += 2;
                    } else {
                        i++;
                    }
                }
            }

            else if (line[0] == 'E') {
                printf("\nEnd of program.\n");
                break;
            }
        }
    } 
    else {
        printf("\nError: Program name does not match header record.\n");
    }

    fclose(fp);
}

