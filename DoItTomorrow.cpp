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
    unsigned int n;
    scanf("%d",&n);

    std::vector< pair<int,int> > work;

    pair <int,int> p;

    unsigned int i;
    int a,b;
    for(i=0;i<n;i++) {
        scanf("%d %d",&a,&b);
        p = make_pair(b,a);
        work.PB(p);
    }

    sort(work.begin(),work.end());

    int day = (work.back()).first - (work.back()).second;

    FORD(i,work.size()-2,0) {
        if(work[i].first<day)
            day = work[i].first-work[i].second;
        else
            day -= work[i].second;
    }

    printf("%d",day);
    return 0;
}
