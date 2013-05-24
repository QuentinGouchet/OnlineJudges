#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cctype>
#include <cerrno>
#include <algorithm>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
#define BIG 1000000
#define OFFSET 140000

using namespace std;

int tree[BIG];
int places[BIG];

int update (int a,int b) {          //will add b for all the values right to a
    a += 2*OFFSET;
    while(a>0) {
        tree[a] += b;
        a /= 2;
    }
    return 0;
}

int sum_up (int a) {                //will sum up the tree how many movies are before
    a += 2*OFFSET;
    int result = 0;
    while(a>0) {
        if(a%2==1)
            result += tree[a^1];
        a /= 2;
    }
    return result;
}

int reset () {                          //reset all memory to 0
    memset(tree,0,sizeof(int)*BIG);
    memset(places,0,sizeof(int)*BIG);
    return 0;
}

int main()
{
    int testcases;
    scanf("%d",&testcases);

    int n,m;
    while(testcases--) {
        scanf("%d %d",&n,&m);

        reset();

        int a;
        for(int i=0;i<n;i++){   //create the initial tree
            a = i+OFFSET;
            places[i] = a;
            update(a,1);        //you add one to all the movies after a
        }

        int new_pos = OFFSET-1; //will be the first position of the movie

        int res;
        for(int i=0;i<m;i++) {
            scanf("%d",&a);
            a--;

            res = sum_up(places[a]);    //you count how many movies are before the movie a

            update(places[a],-1);       //you take off 1 for all the movies on the right of a
            places[a] = new_pos;        //you put a at the beggining
            update(new_pos,1);          //you add 1 to all movies => the movies at the right of a will actually have 1-1=0 and the other one +1
            new_pos--;                  //update next position for next movie

            printf("%d",res);           //print how many cars where before
            if(i<m-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
