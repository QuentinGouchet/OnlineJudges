#include<stdio.h>
#include <vector>
#include <algorithm>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

using namespace std;

int main()
{
    int N,R;
    scanf("%d %d",&N,&R);
    int scenario = 1;

    while(N!=0 && R!=0) {
       vector<int> set;
       for(int i=0;i<N;i++)
         set.PB(i);

       vector< pair< int,pair <int,int> > > edges;

       int a,b,weight;
       for(int i=0;i<R;i++) {
           scanf("%d %d %d",&a,&b,&weight);
            edges.PB(MP(weight,MP(a,b)));
       }

       sort(edges.begin(),edges.end());

       int begin,end,nb_passengers;
       scanf("%d %d %d",&begin,&end,&nb_passengers);

       int min,tmp;

       int i = edges.size()-1;
       while(set[begin-1]!=set[end-1] && i>=0) {
            if(set[edges[i].S.F-1]!=set[edges[i].S.S-1]) {
                min = edges[i].F;
                tmp = set[edges[i].S.S-1];
                for(int j=0;j<set.size();j++) {
                    if(set[j]==tmp)
                        set[j] = set[edges[i].S.F-1];
                }
            }
            i--;
       }

       printf("Scenario #%d\n",scenario);
       scenario++;
       if(nb_passengers%(min-1)==0)
            printf("Minimum Number of Trips = %d\n",nb_passengers/(min-1));
       else
            printf("Minimum Number of Trips = %d\n",nb_passengers/(min-1)+1);
       printf("\n");
       scanf("%d %d",&N,&R);
    }
    return 0;
}
