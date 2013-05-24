#include <stdio.h>
#include <vector>
#include <queue>
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define INF 2147483647

using namespace std;

int n;

vector< vector<int> > E;
vector< vector<int> > F;
vector< vector<int> > C;

pair<int,vector<int> > BFS (int s,int t) {
    vector<int> P (n,-1);
    P[s] = -2;

    vector<int> M (n,-1);
    M[s] = INF;

    queue<int> Q;
    Q.push(s);

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for(int i=0;i<E[u].size();i++) {
            int v = E[u][i];

            if(C[u][v]-F[u][v]>0 && P[v]==-1) {
                P[v] = u;
                M[v] = min(M[u],C[u][v]-F[u][v]);

                if(v != t)
                    Q.push(v);
                else
                    return MP(M[t],P);
            }
        }
    }
    return MP(0,P);
}

pair<int,vector< vector<int> > > edmondsKarp(int s,int t) {
    int f = 0;

    vector<int> v(n,0);
    for(int i=0;i<n;i++)
        F.PB(v);

    while(1) {
        pair<int,vector<int> > tmp = BFS(s,t);

        if(tmp.F==0)
            break;

        f += tmp.F;
        int v = t;
        int u;
        while(v!=s) {
            u = tmp.S[v];
            F[u][v] += tmp.F;
            F[v][u] -= tmp.F;
            v = u;
        }
    }
    return MP(f,F);
}

int set_capacity() {
     for(int i=0;i<n;i++) {
        vector<int> v(n,0);
        C.PB(v);
    }
    return 0;
}

int main() {
	scanf("%d",&n);

    set_capacity();

    for(int i=0;i<n;i++) {
		vector<int> r;
		E.PB(r);
    }

    int a,b;
	for(int i=0;i<n-1;i++) {
		scanf("%d",&a);

		for(int j=0;j<a;j++) {
			scanf("%d",&b);
			E[i].PB(b-1);
			E[b-1].PB(i);

			if(i==0 || b==n)
                C[i][b-1] = 1;
            else
                C[i][b-1] = INF;
		}
	}

    pair<int,vector< vector<int> > > res = edmondsKarp(0,n-1);

	printf("%d\n",res.F);

	return 0;
}
