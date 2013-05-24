#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define PB push_back

using namespace std;

int main()
{
    int M;
    scanf("%d",&M);

    std::vector< pair<int,int> > segments;

    int a,b;
    scanf("%d %d",&a,&b);
    pair<int,int> p;

    while(a!=0 || b !=0) {
        if(a<M && b>0) {
            p = make_pair(a,b);
            segments.PB(p);
        }
        scanf("%d %d",&a,&b);
    }

    if(segments.size()==0) {
        printf("No solution");
        return 0;
    }

    std::sort(segments.begin(),segments.end());

    unsigned int i = 0;

    /*printf("Liste triee et purgee:\n");
    for(i=0;i<segments.size();i++)
        printf("%d %d\n",segments[i].first,segments[i].second);
    printf("\n");*/

    if (segments[0].first>0) {
        printf("No solution");
        return 0;
    }

    std::vector< pair<int,int> > output;
    output.PB(segments[0]);

    //printf("\nLe dernier element est (%d,%d).\n\n",(output.back()).first,(output.back()).second);

    int debut = 0,end = output[0].second;
    i = 1;
    while(end<M) {
        if(segments[i].first<=debut && segments[i].second>end) {
            //printf("ON REMPLACE LE DERNIER ELEMENT\n");
            //printf("segments[%d].first=%d\nsegments[%d].second=%d\n",i,segments[i].first,i,segments[i].second);
            //printf("Le dernier element etait (%d,%d) ",(output.back()).first,(output.back()).second);
            end = segments[i].second;
            output.erase(output.end());
            output.PB(segments[i]);
            //printf("et devient (%d,%d).\n",(output.back()).first,(output.back()).second);
        }
        else if (segments[i].first<=end && segments[i].first>debut && segments[i].second>end) {
            //printf("ON AJOUTE UN ELEMENT\n");
            //printf("segments[%d].first=%d\nsegments[%d].second=%d\n",i,segments[i].first,i,segments[i].second);
            //printf("Le dernier element est (%d,%d) ",(output.back()).first,(output.back()).second);
            end = segments[i].second;
            debut = (output.back()).second;
            output.PB(segments[i]);
            //printf("et apres lajout c'est (%d,%d).\n",(output.back()).first,(output.back()).second);
        }
        else if (segments[i].first>end) {
            //printf("segments[%d].first=%d\nsegments[%d].second=%d\n",i,segments[i].first,i,segments[i].second);
            //printf("Le dernier element est (%d,%d).\n",(output.back()).first,(output.back()).second);
            printf("No solution");
            return 0;
        }
        i++;
    }

    printf("%d\n",output.size());

    for(i=0;i<output.size()-1;i++)
        printf("%d %d\n",output[i].first,output[i].second);

    printf("%d %d",(output.back()).first,(output.back()).second);

    return 0;
}
