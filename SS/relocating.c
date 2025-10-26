#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void convert(char hex_mask[], char bit_mask[]);
void display_file_content(const char *filename);


void main()
{
  FILE* fp;
  char filename[50],name[10], line[50], namecheck[10], staddr[10], bitmask_hex[13], bitmask_binary[49];
  
  int i,j,staddr1,start_addr,text_addr,opcode,addr,actual_addr;
  
  printf("Enter program name: ");
  scanf("%s", name);

  printf("Enter object file name (with extension): ");
  scanf("%s", filename);

  fp= fopen(filename,"r");
  if(fp==NULL)
  {
    printf("Unable to open file\n");
    exit(1);
  }
  printf("Enter the starting addr\n");
  scanf("%x", &start_addr);
  
  fscanf(fp, "%s", line);
  if (line[0] != 'H')
  {
    printf("Error: Invalid object program format.\n");
    fclose(fp);
    exit(1);
  }

  for (i = 2, j = 0; line[i] != '^' && line[i] != '\0'; i++, j++)
    namecheck[j] = line[i];
  namecheck[j] = '\0';
  
  printf("\nProgram name from object file: %s\n", namecheck);

  if (strcmp(name, namecheck) == 0)
  {
    printf("\n--- Relocating Loader ---\n\n");

while (fscanf(fp, "%s", line) != EOF)
{
    if (line[0] == 'T')
    {
    for (i = 2, j = 0; i < 8 && j < 6; i++, j++)
    staddr[j] = line[i];
  staddr[j] = '\0';
  
  text_addr = (int)strtol(staddr, NULL, 16);
  text_addr += start_addr; 

  for (i = 12, j = 0; j < 12 && line[i] != '^' && line[i] != '\0'; i++, j++)
    bitmask_hex[j] = line[i];
  bitmask_hex[j] = '\0';
  
  convert(bitmask_hex, bitmask_bin);

  printf("Text record starting at relocated address: %04X\n", text_addr);
printf("Bitmask (Hex): %s\nBitmask (Binary): %s\n\n", bitmask_hex, bitmask_bin);

  i = i + 1;
  j = 0;
  while (line[i] != '$' && line[i] != '\0')
  {
  if (line[i] != '^')
  {
    char op[3], addr_str[5];
    op[0] = line[i];
    op[1] = line[i + 1];
    op[2] = '\0';
    
    addr_str[0] = line[i + 2];
    addr_str[1] = line[i + 3];
    addr_str[2] = line[i + 4];
    addr_str[3] = line[i + 5];
    addr_str[4] = '\0';

  opcode = (int)strtol(op, NULL, 16);
  addr = (int)strtol(addr_str, NULL, 16);

  if (bitmask_bin[j] == '1')
    actual_addr = addr + start_addr;
  else
    actual_addr = addr;

  printf("00%04X\t%02X%04X\n", text_addr, opcode, actual_addr);

    text_addr += 3;
    i += 6;
    j++;
  }
  else
    i++;
  }
    printf("\n");
  }

            else if (line[0] == 'E')
            {
                printf("\nEnd of program.\n");
                break;
            }
        }
    }
    else
    {
        printf("\nError: Program name does not match header record.\n");
    }

    fclose(fp);
}


void convert(char hex_mask[], char bit_mask[])
{
    int i;
    strcpy(bit_mask, "");
    for (i = 0; i < strlen(hex_mask); i++)
    {
        switch (hex_mask[i])
        {
        case '0': strcat(bit_mask, "0000"); break;
        case '1': strcat(bit_mask, "0001"); break;
        case '2': strcat(bit_mask, "0010"); break;
        case '3': strcat(bit_mask, "0011"); break;
        case '4': strcat(bit_mask, "0100"); break;
        case '5': strcat(bit_mask, "0101"); break;
        case '6': strcat(bit_mask, "0110"); break;
        case '7': strcat(bit_mask, "0111"); break;
        case '8': strcat(bit_mask, "1000"); break;
        case '9': strcat(bit_mask, "1001"); break;
        
        case 'A': case 'a': strcat(bit_mask, "1010"); break;
        case 'B': case 'b': strcat(bit_mask, "1011"); break;
        case 'C': case 'c': strcat(bit_mask, "1100"); break;
        case 'D': case 'd': strcat(bit_mask, "1101"); break;
        case 'E': case 'e': strcat(bit_mask, "1110"); break;
        case 'F': case 'f': strcat(bit_mask, "1111"); break;
        }
    }
}
