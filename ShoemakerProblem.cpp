#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define PB push_back
#define min(a,b) (a<=b?a:b)
#define FORD(i,a,b) for(int _b=(b),i=(a); i>=_b; --i)

using namespace std;

int main()
{
    int nb_cas;
    scanf("%d",&nb_cas);

    while(nb_cas--) {
        std::vector <pair<long double,int> > jobs;

        int n;
        scanf("%d",&n);

        long double f;
        int a,b;
        for(unsigned int i=0;i<n;i++) {
            scanf("%d %d",&a,&b);
            f = (long double)a/(long double)b;
            jobs.PB(make_pair(f,i+1));
        }

        sort(jobs.begin(),jobs.end());

        for(unsigned int i=0;i<n;i++) {
            printf("%d",jobs[i].second);
            if(i<n-1)
                printf(" ");
        }

        printf("\n");
        if(nb_cas)
            printf("\n");
    }
    return 0;
}
