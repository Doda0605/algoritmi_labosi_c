#include<stdio.h>
#include <time.h>

int BC(int n, int k);

int main()
{
        int n,k;
        time_t t1, t2;

        printf("Enter n and k : ");
        scanf("%d%d",&n,&k);
        t1 = clock();
        printf("%\nBinomial coefficient\n",BC(n,k));
        printf("%d\n",BC(n,k));
        t2 = clock();
        printf("Vrijeme formiranja niza je %dms\n", t2-t1);

        return 0;
}

int BC(int n, int k)
{
        if(k==0 || k==n)
                return 1;
        return BC(n-1,k-1) + BC(n-1,k);
}