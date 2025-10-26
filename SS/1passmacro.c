#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void macro_pass(char label[10], char opcode[10], char operand[50]);

int main()
{
    char label[10], opcode[10], operand[50];
    macro_pass(label, opcode, operand);
    return 0;
}

void macro_pass(char label[10], char opcode[10], char operand[50])
{
    FILE *f1, *namtab, *deftab, *output;
    char name[10], opcode1[10], operand1[50], argtab[10][20];
    int argCount = 0;

    f1 = fopen("input.txt", "r");
    namtab = fopen("namtab.txt", "w+"); 
    deftab = fopen("deftab.txt", "w+"); 
    output = fopen("output.txt", "w+"); 
    
    if (!f1)
    {
        printf("Error: input.txt not found!\n");
        return;
    }

    fscanf(f1, "%s\t%s\t%s", label, opcode, operand);

    while (strcmp(opcode, "END") != 0)

        if (strcmp(opcode, "MACRO") == 0)
        {
            char formal[10][20];
            int param_count = 0;

            fprintf(namtab, "%s\n", label);
            rewind(namtab);

            fprintf(deftab, "%s\t%s\n", label, operand);

            char temp[50];
            strcpy(temp, operand);
            char *token = strtok(temp, ",");
            while (token != NULL)
            {
                strcpy(formal[param_count++], token);
                token = strtok(NULL, ",");
            }

            fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
            while (strcmp(opcode, "MEND") != 0)
            {
                if (operand[0] == '&')
                {
                    for (int k = 0; k < param_count; k++)
                    {
                        if (strcmp(operand, formal[k]) == 0)
                        {
                            sprintf(operand, "?%d", k + 1);
                            break;
                        }
                    }
                }
                fprintf(deftab, "%s\t%s\n", opcode, operand);
                fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
            }
            fprintf(deftab, "%s\n", opcode);
        }

        else
        {
            rewind(namtab);
            int found = 0;

            while (fscanf(namtab, "%s", name) != EOF)
            {
                if (strcmp(opcode, name) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (found)
            {
                argCount = 0;
                char *token = strtok(operand, ",");
                while (token != NULL)
                {
                    strcpy(argtab[argCount++], token);
                    token = strtok(NULL, ",");
                }

                rewind(deftab);
                while (fscanf(deftab, "%s\t%s", opcode1, operand1) != EOF)
                {
                    if (strcmp(opcode1, opcode) == 0)
                        break;
                }

                fprintf(output, ".\t%s\t", opcode);
                for (int i = 0; i < argCount; i++)
                {
                    fprintf(output, "%s%s", argtab[i], (i == argCount - 1) ? "" : ",");
                }
                fprintf(output, "\n");

                while (fscanf(deftab, "%s\t%s", opcode1, operand1) != EOF && strcmp(opcode1, "MEND") != 0)
                {
                    if (operand1[0] == '?')
                    {
                        int index = operand1[1] - '1';
                        if (index >= 0 && index < argCount)
                        {
                            fprintf(output, "-\t%s\t%s\n", opcode1, argtab[index]);
                        }
                    }
                    else
                    {
                        fprintf(output, "-\t%s\t%s\n", opcode1, operand1);
                    }
                }
            }
            else
            {
                fprintf(output, "%s\t%s\t%s\n", label, opcode, operand);
            }
        }

        fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
    }

    fprintf(output, "%s\t%s\t%s\n", label, opcode, operand);

    fclose(f1);
    fclose(namtab);
    fclose(deftab);
    fclose(output);

    printf("\nSuccessfully implemented One Pass Macro Assembler!\n");

    char *files[] = {"input.txt", "namtab.txt", "deftab.txt", "output.txt"};
    char line[200];
    for (int i = 0; i < 4; i++)
    {
        FILE *fp = fopen(files[i], "r");
        if (!fp)
            continue;
        printf("\n========== %s ==========\n", files[i]);
        while (fgets(line, sizeof(line), fp) != NULL)
            printf("%s", line);
        fclose(fp);
    }
}

