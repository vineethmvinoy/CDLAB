#include <stdio.h>

struct transition
{
    int start;
    char sym;
    int end;
};

int n;
int nt;
struct transition t[10];
int result[20];

void clear()
{
    for (int i = 0; i < 20; i++)
    {
        result[i] = -1;
    }
}

void e_closure(int s)
{
    result[s]=1;
    for(int i=0;i<nt;i++){
        if(t[i].start==s&&t[i].sym=='e'&&result[t[i].end]==-1){
            e_closure(t[i].end);
        }
    }
}

void main()
{
    printf("Enter number of states and transitions: ");
    scanf("%d %d", &n, &nt);
    printf("Enter the transitions in proper format:\n");
    for (int i = 0; i < nt; i++)
    {
        scanf("%d %c %d", &t[i].start, &t[i].sym, &t[i].end);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        clear();
        e_closure(i);
        printf("Episolon closure of Q%d = { ",i);
        for(int j=0;j<n;j++){
            if(result[j]==1){
                printf("Q%d ",j);
            }
        }
        printf("}\n");

    }
}