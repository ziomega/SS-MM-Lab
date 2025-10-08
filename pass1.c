#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void p1(char label[10], char opcode[10], char operand[10], char code[10], char mnemonic[3]);

void display();

int main()
{
  char label[10];
  char opcode[10];
  char operand[10];
  char code[10];
  char mnemonic[3];
  
  p1(label, opcode, operand, code, mnemonic);
  return 0;
}

void p1(char label[10], char opcode[10], char operand[10], char code[10], char mnemonic[3])
{
  int locctr, start, length;
  FILE *f1, *f2, *f3, *f4, *f5;
  
  f1= fopen("input.txt", "r");
  f2= fopen("optab.txt", "r");  
  f3= fopen("symtab.txt", "w");
  f4= fopen("intermediate.txt", "w");
  f5= fopen("length.txt", "w");  
  
  fscanf(f1, "%s\t%s\t%s", label, opcode, operand);
  
  if (!f1 || !f2 || !f3 || !f4 || !f5) 
  {
        printf("Error opening files!\n");
        return;
  }
  
  if(strcmp(opcode,"START")==0)
  {
    start= atoi(operand);
    locctr= start;
    fprintf(f4,"\t%s\t%s\t%s\n", label, opcode, operand);
    fscanf(f1, "%s\t%s\t%s", label, opcode, operand);  
  }
  else
    locctr=0;
    
    
    
  while(strcmp(opcode,"END")!=0)
  {
    fprintf(f4,"%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    
    
    if(strcmp("**",label)!=0)
    {
      fprintf(f3,"%s\t%d\n", label, locctr);
    }
    
    
    
    rewind(f2);
    int found=0;
      
    while(fscanf(f2,"%s\t%s", code, mnemonic) !=EOF)
    {
      if(strcmp(code,opcode)==0)
      {
        locctr+=3;
        found=1;
        break;
      }
    }
    rewind(f2);

    
    if(!found)
    {
    if(strcmp("WORD",opcode)==0)
      locctr+=3;
      
    if(strcmp("BYTE",opcode)==0)
      locctr++;   
      
    if(strcmp("RESW",opcode)==0)
      locctr+=(3*atoi(operand)); 
      
    if(strcmp("RESB",opcode)==0)
      locctr+=atoi(operand);
    }
      
    fscanf(f1, "%s\t%s\t%s", label, opcode, operand);  
  }
  
  fprintf(f4,"%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    
  fclose(f1);
  fclose(f2);
  fclose(f3);
  fclose(f4);
  
  length= locctr-start;
  fprintf(f5,"%d", length);
  fclose(f5);
}

