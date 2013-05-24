
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n,k;
    scanf("%d %d",&n,&k);

    int ans = -1;
    int aux = -1;
    int T[10001];

    for(int i=0;i<k;i++){
        int aux2 = 0;
        memset(T,0,sizeof(T));

        int x;
        for(int j=0;j<n;j++){
            scanf("%d",&x);
            x = n+1-x;

            for(int l=x-1;l>0;l-=(l & -l)) {
                aux2 += T[l];
                printf("%d\n",l);
            }
            for(int l=x;l<=n;l+=(l & -l))
                T[l]++;
        }

        if(aux2>aux){
            aux = aux2;
            ans = i+1;
        }
    }

    printf("%d\n",ans);

    return 0;
}
