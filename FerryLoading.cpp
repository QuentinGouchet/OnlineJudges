#include <stdio.h>
#include <vector>
#include <string>
#include <cassert>
#define PB push_back

using namespace std;

vector<int> cars;
vector<int> partiel_sums;
vector<char *> side;

int initial_length;
int sum;
int length;

int mem[200][20000];
int backlinks[200][20000];

int load_ferry (int lengthLeft, int position) {

    if(mem[position][lengthLeft]!=-1)
        return mem[position][lengthLeft];

    int lengthRight = length-(partiel_sums[position]-(length-lengthLeft));
    //printf("partial sums=%d cars.size()=%d\n",partiel_sums[initial_length-cars.size()],cars.size());
    //printf("cars 0=%d lengthL=%d lengthR=%d\n",cars[0],lengthLeft,lengthRight);

    if(initial_length==position || (lengthLeft<cars[position] && lengthRight<cars[position])) {
            backlinks[position][lengthLeft] = 0;
            mem[position][lengthLeft] = 0;
            return 0;
    }

    //printf("car=%d\n",cars[0]);
    //printf("left=%d right=%d\n",lengthLeft,lengthRight);

    int tmp = cars[position];

    if(lengthLeft==lengthRight) {
        backlinks[position][lengthLeft] = 1;
        return mem[position][lengthLeft] = 1 + load_ferry(lengthLeft-tmp,position+1);
    }

    if(lengthLeft<tmp && lengthRight>=tmp) {
        backlinks[position][lengthLeft] = 2;
        return mem[position][lengthLeft] = 1 + load_ferry(lengthLeft,position+1);
    }

    if(lengthLeft>=tmp && lengthRight<tmp) {
        backlinks[position][lengthLeft] = 1;
        return mem[position][lengthLeft] = 1 + load_ferry(lengthLeft-tmp,position+1);
    }

    int var1 = load_ferry(lengthLeft,position+1);
    int var2 = load_ferry(lengthLeft-tmp,position+1);

    int var3 = 1+(var1>=var2?var1:var2);

    backlinks[position][lengthLeft] = (var1>=var2?2:1);
    mem[position][lengthLeft] = var3;

    return var3;
}

int reset () {
    cars.clear();
    partiel_sums.clear();
    side.clear();
    initial_length = 0;
    sum = 0;
    for(int i=0;i<200;i++) {
        for(int j=0;j<20000;j++){
            mem[i][j] = -1;
            backlinks[i][j] = -1;
        }
    }
    return 0;
}

void reconstruct (int depth,int l) {
    //printf("backlink=%d\n",backlinks[depth][l]);
    if(backlinks[depth][l]==0)
        return ;
    else if(backlinks[depth][l]==1) {
        side.PB("port");
        reconstruct(depth+1,l-cars[depth]);
    }
    else if(backlinks[depth][l]==2) {
        side.PB("starboard");
        reconstruct(depth+1,l);
    }
}

int main()
{
    int test_cases;
    scanf("%d",&test_cases);

    while(test_cases--) {
        reset();

        scanf("%d",&length);
        length *= 100;

        partiel_sums.PB(0);

        int a;
        while(scanf("%d",&a) && a!=0) {
            cars.PB(a);
            sum += a;
            partiel_sums.PB(sum);
            initial_length++;
        }

        load_ferry(length,0);

        reconstruct(0,length);

        printf("%d\n",side.size());
        //assert(answer<=side.size());
        for(unsigned int i=0;i<side.size();i++)
            printf("%s\n",side[i]);

        if(test_cases)
            printf("\n");
    }
    return 0;
}
