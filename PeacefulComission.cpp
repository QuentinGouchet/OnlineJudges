#include <stdio.h>
#include <vector>
#define PB push_back
#define MP make_pair

using namespace std;

vector< vector<int> > graph;
vector<int> deputies;
vector<int> visited;

int DFS (int n) {
    visited[n] = 1;
    if(deputies[n]==-1) {
        if(n%2==0 && deputies[n+1]!=-1)
            deputies[n] = 1 - deputies[n+1];
        else if(n%2==1 && deputies[n-1]!=-1)
            deputies[n] = 1 - deputies[n-1];
        else
            deputies[n] = 0;
    }
    for(unsigned int i=0;i<graph[n].size();i++) {
        if(visited[graph[n][i]-1]==0) {
            deputies[graph[n][i]-1] = 1 - deputies[n];
            DFS(graph[n][i]-1);
        }
    }
    return 0;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<2*n;i++) {
        vector<int> p;
        graph.PB(p);
    }

    int a,b;
    for(int i=0;i<m;i++) {
        scanf("%d %d",&a,&b);
        graph[a-1].PB(b);
        graph[b-1].PB(a);
    }

    for(int i=0;i<2*n;i++) {
        deputies.PB(-1);
        visited.PB(0);
    }

    deputies[0] = 1;

    int changement = 1;
    int i;
    while(changement) {
        changement--;
        i = 0;
        while(visited[i]==1 && i<visited.size())
            i++;
        if(visited[i]==0 && graph[i].size()>0) {
            DFS(i);
            changement++;
        }
    }

    /*for(int i=0;i<2*n;i++)
        printf("%d ",deputies[i]);*/

    vector<int> first;
    vector<int> second;

    for(int i=0;i<deputies.size()/2;i++) {
        if(deputies[2*i]==-1) {
            first.PB(2*i+1);
            second.PB(2*i+1);
        }
        else if(deputies[2*i+1]==-1) {
            first.PB(2*i+2);
            second.PB(2*i+2);
        }
        else {
            if(deputies[2*i]==0) first.PB(2*i+1);
            if(deputies[2*i]==1) second.PB(2*i+1);
            if(deputies[2*i+1]==0) first.PB(2*i+2);
            if(deputies[2*i+1]==1) second.PB(2*i+2);
        }
    }

    int test = 1;

    for(int i=0;i<deputies.size();i++) {
        if((deputies[2*i]==0 && deputies[2*i+1]==0) || (deputies[2*i]==1 && deputies[2*i+1]==1))
            test = 0;
    }

    if(test) {
        for(int i=0;i<first.size();i++)
            printf("%d\n",first[i]);
    }
    else
        printf("NIE\n");

    return 0;
}
