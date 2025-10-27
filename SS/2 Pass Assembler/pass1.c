#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void p1(char label[10], char opcode[10], char operand[10], char code[10], char mnemonic[3]);

int main()
{
  char label[10], opcode[10], operand[10], code[10], mnemonic[3];
  
  p1(label, opcode, operand, code, mnemonic);
  return 0;
  
}


void p1(char label[10], char opcode[10], char operand[10], char code[10], char mnemonic[3])
{
  int locctr=0, staddr=0;
  
  FILE *f1, *f2, *f3, *f4, *f5;
  
  f1= fopen("input.txt", "r");
  f2= fopen("optab.txt", "r");
  f3= fopen("symtab.txt", "w");
  f4= fopen("intermediate.txt","w");
  f5= fopen("length.txt","w");
  
  
  if(!f1 || !f2 || !f3 || !f4 || !f5)
  {
    printf("Error opening files\n");
    return;
  }
  
  fscanf(f1,"%s\t%s\t%s", label, opcode, operand);
  
  if(strcmp(opcode,"START")==0)
  {
    staddr= atoi(operand);
    locctr= staddr;
    fprintf(f4,"\t%s\t%s\t%s\n", label, opcode, operand);
    fscanf(f1,"%s\t%s\t%s", label, opcode, operand);
  }
  
  while(strcmp(opcode,"END")!=0)
  {
    fprintf(f4,"%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    
    if(strcmp("**",label)!=0)
      fprintf(f3,"%s\t%d\t",label, locctr);

      rewind(f2);
      int found=0;
      
      while(fscanf(f2,"%s\t%s", code, mnemonic)!=EOF)
      {
        if(strcmp(code,opcode)==0)
        {
          locctr+=3;
          found=1;
          break;
        }
      }
      
      if(!found)
      {
        if(strcmp(opcode,"BYTE")==0)
        {
          if(operand[0]=='C')
            locctr+=strlen(operand)-3;
          else if(operand[0]=='X')
            locctr+=(strlen(operand)-3)/2;
        }
        else if(strcmp(opcode,"RESB")==0)
          locctr+=atoi(operand);
        
        else if(strcmp(opcode,"WORD")==0)
          locctr+=3;
          
        else if(strcmp(opcode,"RESW")==0)
          locctr+=(atoi(operand))*3;
        
      }
    fscanf(f1,"%s\t%s\t%s", label, opcode, operand);
    }
    
    fprintf(f4,"%d\t%s\t%s\t%s", locctr,label,opcode,operand);
    
    int length= locctr-staddr;
    fprintf(f5,"%d", length);
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    
}   
    
    
  
      
      
    
  
