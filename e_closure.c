#include <stdio.h>
#include <string.h>
#include <ctype.h> 
char trans[100][10];
int k=0;
int stno;
int trap;
void findclo(char st[])
{
    char visited[100][3];
    trap=0;
    strcpy(visited[k++],st);
    for(int i=0;i<stno;i++)
    {
       
        char bufferstate[3];
        char tran[1];
        char endstate[3];
        int j=0;
        int p;
        for(p=0;trans[i][p]!=' ';p++)
        {  
            bufferstate[j++]=trans[i][p];
        }
        p++;
        bufferstate[j]='\0';
        
        j=0;
        for(;trans[i][p]!=' ';p++)
        {   
            tran[j++]=trans[i][p];
        }
        p++;
        tran[j]='\0';
        
        j=0;
        for(;trans[i][p]!='\0';p++)
        {    
            endstate[j++]=trans[i][p];
        }

            endstate[j]='\0';  
            if(strcmp(st,bufferstate)==0)
            if(tran[0]=='e')
        {
            printf(" %s,",endstate);
            for(int l=0;l<k;l++)
            {
                if(strcmp(visited[l],endstate)==0)
                trap=1;
            }        
            if(trap!=1)
            findclo(endstate);
        }
    }
}
void main()
{
printf("Enter the number of states\n");
int n;
scanf("%d",&n);
printf("Enter the states\n");
char st[n][3];
for(int i=0;i<n;i++)
{
    scanf(" %s",st[i]);
}
for(int i=0;i<n;i++)
{
    printf(" %s",st[i]);
}
printf("\nEnter the number of transitions\n");

scanf("%d",&stno);
printf("Enter the transitions\n");

for(int i=0;i<stno+1;i++)
{
fgets(trans[i],sizeof(trans[i]),stdin);
}
for(int i=0;i<stno+1;i++)
{
puts(trans[i]);
}
for(int i=0;i<n;i++)
{
    printf("Epsilon Closure of %s :{ %s",st[i],st[i]);
  findclo(st[i]);
  printf("}\n");
}
}
