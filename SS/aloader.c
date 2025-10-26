#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{

  int i,j,staddr1;
  
  char filename[50], name[10], line[50], namecheck[10],staddr[10]; 
  
  FILE *fp;
  
  printf("Enter program name: \n");
  scanf("%s", name);
  
  printf("Enter file name incl. extension:\n");
  scanf("%s", filename);
  
  fp = fopen(filename,"r");
  
  if(fp==NULL)
  {
    printf("Unable to open file\n");
    exit(1);
  }
  
  fscanf(fp, "%s", line);
  
  if(line[0]!='H')
  {
    printf("Invalid Format\n");
    fclose(fp);
    exit(1);
  }
  
  for(i=2,j=0;i<8 && j<6; i++,j++)
    namecheck[j]= line[i];
  namecheck[j]='\0';
  
  printf("Program name from object file: %s\n", namecheck);
  
  if(strcmp(name,namecheck)!=0)
    {
      printf("Program doesnt match\n");
      fclose(fp);
      exit(1);
    }
  else 
  {
    printf("Loading program.....\n");
    
    while(fscanf(fp,"%s",line)!=EOF)
    {
      if(line[0]=='T')
      {
        for(i=2,j=0;i<8 && j<6 ;i++,j++)
          staddr[j]=line[i];
        staddr[j]='\0';
        
        staddr1= (int)strtol(staddr,NULL,16);
        
        i=12;
        while(line[i]!='$' && line[i]!='\0')
        {
          if(line[i]=='^')
            i++;
          else
          {
            printf("00%04X \t %c %c \n", staddr1,line[i],line[i+1]);
            staddr1++;
            i+=2;
          }
        }
      }
      else if(line[0]=='E')
      {
        printf("End of Program \n");
        break;
      }
    }
  }
  fclose(fp);
}
          
        
        
  
  
