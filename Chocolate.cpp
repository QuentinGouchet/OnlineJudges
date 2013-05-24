#include <stdio.h>
#include <vector>
#include <algorithm>
#define PB push_back
#define max(a,b) a>=b?a:b

using namespace std;

int main()
{
    int m,n,a;
    scanf("%d %d",&m,&n);

    vector<int> vw;
    for(int i=0;i<m-1;i++) {
        scanf("%d",&a);
        vw.PB(a);
    }

    sort(vw.begin(),vw.end());

    vector<int> hw;
    for(int i=0;i<n-1;i++) {
        scanf("%d",&a);
        hw.PB(a);
    }

    sort(hw.begin(),hw.end());

    int vertical_cuts = 1;
    int horizontal_cuts = 1;

    int cost = 0;

    while(hw.size()>0 && vw.size()>0) {
        if(hw.back()>vw.back()) {
            cost += vertical_cuts*hw.back();
            hw.erase(hw.end()-1);
            horizontal_cuts++;
        }
        if(hw.back()<vw.back()) {
            cost += horizontal_cuts*vw.back();
            vw.erase(vw.end()-1);
            vertical_cuts++;
        }
        if(hw.back()==vw.back()) {
            if(vertical_cuts>=horizontal_cuts) {
                cost += horizontal_cuts*vw.back();
                vw.erase(vw.end()-1);
                vertical_cuts++;
            }
            else {
                cost += vertical_cuts*hw.back();
                hw.erase(hw.end()-1);
                horizontal_cuts++;
            }
        }
    }

    int sum = 0;

    if(hw.size()==0) {
        for(int i=0;i<vw.size();i++)
            sum += vw[i];
        cost += sum*horizontal_cuts;
    }

    if(vw.size()==0) {
        for(int i=0;i<hw.size();i++)
            sum += hw[i];
        cost += sum*vertical_cuts;
    }

    printf("%d\n",cost);

    return 0;
}
