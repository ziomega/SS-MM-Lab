#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void p2(char label[10], char opcode [10], char operand[10], char symbol[10], char code[10], char mnemonic[3]);


int main() 
{
    char label[10];
    char opcode[10];
    char operand[10];
    char symbol[10];
    char code[10];
    char mnemonic[3];
    
    p2(label, opcode, operand, symbol, code, mnemonic);
    return 0;
}

void p2(char label[10], char opcode [10], char operand[10], char symbol[10], char code[10], char mnemonic[3])
{
  int locctr;
  int start;
  int length;
  
  FILE *f1, *f2, *f3, *f4, *f5;
  
    f1 = fopen("intermediate.txt", "r");
    f2 = fopen("optab.txt", "r");
    f3 = fopen("symtab.txt", "r");
    f4 = fopen("output.txt", "w");
    f5 = fopen("length.txt", "r");

    if (!f1 || !f2 || !f3 || !f4 || !f5) {
        printf("Error opening files!\n");
        return;
    }
    
    fscanf(f5, "%d", &length);
    
    fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
    
    if(strcmp(opcode,"START")==0)
    {
      start =atoi(operand);
      fprintf(f4,"H^%s^%04d^%04d\n", label, start, length);
    fscanf(f1, "%d\t%s\t%s\t%s", &locctr, label, opcode, operand);
    }
    else
      start=0;
    
    fprintf(f4,"T^%04d^",locctr);
    int tstart = locctr;
    char trecord[100]="";
    int tlen=0;
    
    while (strcmp(opcode, "END") != 0)
    {
      int found=0;
      char objcode[10]="";
      
      rewind(f2);
      while (fscanf(f2, "%s\t%s", code, mnemonic) != EOF)
    {
      if (strcmp(opcode, code) == 0)
        {
          rewind(f3);
          while (fscanf(f3, "%s\t%d", symbol, &locctr) != EOF) {
    if (strcmp(symbol, operand) == 0) {
        sprintf(objcode, "%s%04d", mnemonic, locctr);
        break;
    }
}
  rewind(f3);
  found=1;
  break;
}
}
  if (!found) 
  {
   if (strcmp(opcode, "WORD") == 0)
                sprintf(objcode, "%06d", atoi(operand));

 else if (strcmp(opcode, "BYTE") == 0)
                sprintf(objcode, "%x", operand[2]);
                
  else if (strcmp(opcode, "RESW") == 0 || strcmp(opcode, "RESB") == 0)
                strcpy(objcode, "");
  }

        if (strlen(objcode) > 0) {
            strcat(trecord, "^");
            strcat(trecord, objcode);
            tlen += strlen(objcode) / 2; 
        }

        fscanf(f1, "%d\t%s\t%s\t%s", &locctr, label, opcode, operand);
    }

    fprintf(f4, "%02X%s\n", tlen, trecord); 
    fprintf(f4, "E^%04d\n", start); 

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);

    printf("PASS 2 completed successfully! Check output.txt.\n");
}


      
      
    
      



  


