#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *input, *namtab, *deftab, *output;
    char label[20], opcode[20], operand[50];
    char mname[20], defop[20], defopnd[50];
    char argtab[10][20], formal[10][20];
    int argCount, i;

    input  = fopen("inputm.txt", "r");
    namtab = fopen("namtab.txt", "w+");
    deftab = fopen("deftab.txt", "w+");
    output = fopen("op.txt", "w");

    if (!input) {
        printf("Error: inputm.txt not found!\n");
        return 1;
    }

    fscanf(input, "%s%s%s", label, opcode, operand);

    while (strcmp(opcode, "END") != 0) {

        if (strcmp(opcode, "MACRO") == 0) {
            fprintf(namtab, "%s\n", label); 
            fprintf(deftab, "%s %s\n", label, operand);

            argCount = 0;
            char *tok = strtok(operand, ",");
            while (tok) {
                strcpy(formal[argCount++], tok);
                tok = strtok(NULL, ",");
            }

            fscanf(input, "%s%s%s", label, opcode, operand);
            while (strcmp(opcode, "MEND") != 0) {
                fprintf(deftab, "%s %s\n", opcode, operand);
                fscanf(input, "%s%s%s", label, opcode, operand);
            }
            fprintf(deftab, "MEND -\n");
        }

        else {
            rewind(namtab);
            int found = 0;

            while (fscanf(namtab, "%s", mname) != EOF) {
                if (strcmp(opcode, mname) == 0) {
                    found = 1;
                     fprintf(output, "%s\t%s\t%s\n", label, opcode, operand);
                    break;
                }
            }

            if (found) {
         
                argCount = 0;
                char *tok = strtok(operand, ",");
                while (tok) {
                    strcpy(argtab[argCount++], tok);
                    tok = strtok(NULL, ",");
                }

    
                rewind(deftab);
                while (fscanf(deftab, "%s%s", defop, defopnd) != EOF) {
                    if (strcmp(defop, opcode) == 0) break;
                }

     
                while (fscanf(deftab, "%s%s", defop, defopnd) != EOF && strcmp(defop, "MEND") != 0) {
                    if (defopnd[0] == '&') {
 
                        for (i = 0; i < argCount; i++) {
                            if (strcmp(defopnd, formal[i]) == 0) {
                                fprintf(output, "-\t%s\t%s\n", defop, argtab[i]);
                                break;
                            }
                        }
                    } else {
                        fprintf(output, "-\t%s\t%s\n", defop, defopnd);
                    }
                }
            } else {

                fprintf(output, "%s\t%s\t%s\n", label, opcode, operand);
            }
        }

        fscanf(input, "%s%s%s", label, opcode, operand);
    }

    fprintf(output, "%s\t%s\t%s\n", label, opcode, operand);
    printf("\n One-Pass Macro Processor executed successfully.\n");

    fclose(input);
    fclose(namtab);
    fclose(deftab);
    fclose(output);
    return 0;
}
