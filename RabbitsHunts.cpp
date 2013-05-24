#include <iostream>
#include <stdio.h>
#include <vector>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define min(a,b) a<=b?a:b

using namespace std;

struct droite {
    int a;
    int b;
    int c;
};
typedef struct droite droite;

int main()
{
    int n;
    scanf("%d",&n);

    vector<pair<int,int> > rabbits;

    int a,b;
    for(int i=0;i<n;i++) {
        scanf("%d %d",&a,&b);
        rabbits.PB(MP(a,b));
    }

    vector<droite> droites;

    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            droite d;
            d.a = rabbits[i].S - rabbits[j].S;
            d.b = rabbits[j].F - rabbits[i].F;
            d.c = rabbits[j].S*rabbits[i].F - rabbits[j].F*rabbits[i].S;
            droites.PB(d);
        }
    }

    vector<int> rabbits_on_lignes;

    for(int i=0;i<droites.size();i++)
        rabbits_on_lignes.PB(0);

    for(int i=0;i<droites.size();i++) {
        for(int j=0;j<n;j++) {
            if(droites[i].a*rabbits[j].F+droites[i].b*rabbits[j].S+droites[i].c==0)
                rabbits_on_lignes[i]++;
        }
    }

    int max = 0;
    for(int i=0;i<rabbits_on_lignes.size();i++) {
        max = rabbits_on_lignes[i]>max?rabbits_on_lignes[i]:max;
        //printf("ligne %d : %d rabbits\n",i+1,rabbits_on_lignes[i]);
    }

    printf("%d\n",max);

    return 0;
}
