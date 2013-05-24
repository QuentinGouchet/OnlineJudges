#include <iostream>
#include <stdio.h>
#include <vector>
#define PB push_back

using namespace std;

vector<long long int> divfact1 (long long int n) {
    vector<long long int> fact1;
    long long int d = 2;
    //long long int p = 1;
    while(n>1) {
        if(n%d==0) {
            fact1.PB(d);
            n /= d;
        }
        else {
            d++; //+= p;
            //p = 2;
        }
        if(d*d>n)
            d = n;
    }
    return fact1;
}

long long int nb_fact1 (long long int n,long long int p) {
    long long int compte = 0;
    long long int P = p;
    while(P<=n) {
        compte += n/P;
        P *= p;
    }
    return compte;
}

int main()
{
    long long int m,n,p,i;

    while(scanf("%lld %lld",&m,&n)==2) {
        vector<long long int> fact1n = divfact1(n);
        while(fact1n.size()>0) {
            i = 0;
            p = fact1n[i];
            while(i+1<fact1n.size() && fact1n[i+1]==fact1n[i])
                i++;
            if(nb_fact1(m,p)<i+1) {
                printf("%lld does not divide %lld!\n",n,m);
                goto next;
            }
            else
                fact1n.erase(fact1n.begin(),fact1n.begin()+i+1);
        }
        printf("%lld divides %lld!\n",n,m);
        next:;
    }
    return 0;
}
