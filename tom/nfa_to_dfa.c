#include <stdio.h>

struct dfastate
{
    int s[10];
};

struct transition
{
    struct dfastate start;
    char sym;
    struct dfastate end;
};

int nn;

struct dfastate dfas[20];

int n;
int nt;
int na;
int nnt;
struct transition t[10];
int result[20];
char alpha[20];

int add(int s[])
{

    for (int i = 0; i < nn; i++)
    {
        int f = 1;
        for (int j = 0; j < 10; j++)
        {
            if (dfas[i].s[j] != s[j])
            {
                f = 0;
                break;
            }
        }
        if (f == 1)
        {
            return 1;
        }
    }
    for (int j = 0; j < 10; j++)
    {
        dfas[nn].s[j] = s[j];
    }
    nn++;
    return 0;
}

void clear(int arr[])
{
    for (int i = 0; i < 20; i++)
    {
        arr[i] = 0;
    }
}

void main()
{
    nn = 0;
    nnt=0;
    printf("Enter number of states,alphabets and transitions: ");
    scanf("%d %d", &n, &na, &nt);
    printf("Enter the alphabets:\n");
    for (int i = 0; i < nt; i++)
    {
        scanf("%c", &alpha[i]);
    }
    printf("Enter the transitions in proper format:\n");
    for (int i = 0; i < nt; i++)
    {
        clear(t[i].start.s);
        clear(t[i].end.s);
        int x, y;
        scanf("%d %c %d", &x, &t[i].sym, &y);
        t[i].start.s[x] = 1;
        t[i].end.s[y] = 1;
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        clear(dfas[i].s);
        dfas[i].s[i] = 1;
        nn++;
    }
    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < na; j++)
        {
            int arr[10];
            clear(arr);
            for (int k = 0; k < nt; k++)
            {
                // if (t[k].start == i && t[k].sym == alpha[j])
                // {
                //     arr[i] = 1;
                // }
            }
            add(arr);
        }
    }
}