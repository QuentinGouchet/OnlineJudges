#include <iostream>
#include <stdio.h>
#include <vector>
#define PB push_back
#define F first
#define S second
#define min(a,b) a<=b?a:b

using namespace std;

vector<int> cuts;
int tmp[52][52];

int cut_stick(int a,int b) {
    if(b-a==1)
        return 0;

    if(tmp[a][b]!=-1)
        return tmp[a][b];

    int cost = 2147483647;

    for(int i=a+1;i<b;i++)
        cost = min(cost,cuts[b]-cuts[a]+cut_stick(a,i)+cut_stick(i,b));

    tmp[a][b] = cost;
    return cost;
}

int reset () {
    for(int i=0;i<52;i++) {
            for(int j=0;j<52;j++) {
                tmp[i][j] = -1;
            }
        }
    cuts.clear();
    return 0;
}

int main()
{
    int l;
    scanf("%d",&l);

    while(l!=0) {
        int nb_cuts;
        scanf("%d",&nb_cuts);

        reset();

        int a;
        cuts.PB(0);
        for(int i=0;i<nb_cuts;i++) {
            scanf("%d",&a);
            cuts.PB(a);
        }

        cuts.PB(l);

        printf("The minimum cutting is %d.\n",cut_stick(0,nb_cuts+1));

        scanf("%d",&l);
    }
    return 0;
}
