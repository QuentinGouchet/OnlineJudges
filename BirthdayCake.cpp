#include <stdio.h>
#include <vector>
#include <string>
#include <cassert>
#define PB push_back
#define MP make_pair
#define F first
#define S second

using namespace std;

int main()
{
    int n;
    vector< pair<int,int> > cherries;
    int above;
    int under;

    while(scanf("%d",&n)==1 && n!=0) {
        cherries.clear();

        int x,y;
        for(int i=0;i<2*n;i++) {
            scanf("%d %d",&x,&y);
            cherries.PB(MP(x,y));
        }

        for(int a=-500;a<=500;a++) {
            for(int b=-500;b<=500;b++) {
                above = 0;
                under = 0;
                for(int i=0;i<cherries.size();i++) {
                    if(a*cherries[i].F+b*cherries[i].S>0)
                        above++;
                    else if(a*cherries[i].F+b*cherries[i].S<0)
                        under++;
                }
                if(above==under && under==n) {
                    printf("%d %d\n",a,b);
                    goto next;
                }
            }
        }
        next:;
    }

    return 0;
}
