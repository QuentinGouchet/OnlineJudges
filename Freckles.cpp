#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#define PB push_back
#define MP make_pair
#define S second
#define F first

using namespace std;

int main()
{
    int nb_cas;
    scanf("%d",&nb_cas);

    while(nb_cas--) {
        int n;
        scanf("%d",&n);

        vector< pair<double,double> > freckles;
        vector<pair <double,pair <int,int> > > edges;
        vector<int> pere;
        double a,b,d;
        int i,j;
        int far_tmp1;

        for(i=0;i<n;i++) {
            scanf("%lf %lf",&a,&b);
            freckles.PB(MP(a,b));
        }

        if(n==1) {
            printf("0.00\n");
            goto next;
        }

        for(i=0;i<n-1;i++) {
            for(j=i+1;j<n;j++) {
                d = sqrt((freckles[i].first-freckles[j].first)*(freckles[i].first-freckles[j].first)+(freckles[i].second-freckles[j].second)*(freckles[i].second-freckles[j].second));
                edges.PB(MP(d,MP(i,j)));
            }
        }

        sort(edges.begin(),edges.end());

        for(i=0;i<n;i++)
            pere.PB(i);

        d = 0;
        for(j=0;j<edges.size();j++) {
            if(pere[edges[j].S.F]!=pere[edges[j].S.S]) {
                d += edges[j].F;
                far_tmp1 = pere[edges[j].S.S];
                for(i=0;i<pere.size();i++) {
                    if(pere[i]==far_tmp1)
                        pere[i] = pere[edges[j].S.F];
                }
            }
        }

        printf("%.2lf\n",d);

        next:
        if(nb_cas)
            printf("\n");
    }
    return 0;
}
