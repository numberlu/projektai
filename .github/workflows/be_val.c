#include <stdio.h>
void skait(int N, int sumst[], int sumeil[], int a[][100])
{
    char str[101];

    for(int j = 0; j < N; ++j)
    {
        printf("Iveskite %d eilutes ", j+1);
        for(int i = 0; i < N; ++i)
        {
            printf("%d skaiciu: ", i+1);
            scanf("%d", &a[j][i]);
    
            sumeil[j]=sumeil[j]+a[j][i];
            sumst[i]=sumst[i]+a[j][i];
        }
    }
}
void rez(int N, int sumst[], int sumeil[], int a[][100], int sumis[])
{
    for(int i=0; i<N; ++i)
    {
        if(sumst[i] != sumst [0]) //patikrina ar tarpusavyje stulpeliu sumos lygio
        {
            printf("Kvadratas nera magiskasis :(\n");
            return;
        }
        if(sumeil [0] != sumst[0]) //patikrina ar pirma eil lygi pirmam stulpeliui
        {
            printf("Kvadratas nera magiskasis :(\n");
            return;
        }
        
        sumis[0]=sumis[0]+a[i][i];
        sumis[1]=sumis[1]+a[i][N-i];
    }

    if(sumeil[0] != sumis[0] && sumeil[0] != sumis[1]) //patikrina ar stulp. sum ir eil. sum lygios istrizainiu sumoms
    {
        printf("Kvadratas nera magiskasis :(\n");
        return;
    }

    printf("Kvadratas magiskasis :)\n");
}
int main()
{
    int N;
    char str[101];
    
    printf("Iveskite sveika skaciu N:\n");
    scanf("%d", &N);
    
    int a[100][100], sumst[100]= {}, sumeil[100] = {}, sumis[2] = {};

    skait(N, sumst, sumeil, a);

    rez(N, sumst, sumeil, a, sumis);

    return 0;
}