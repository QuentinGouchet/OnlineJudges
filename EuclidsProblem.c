#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,q,r,r1,rs,u0,u1,u2,v0,v1,v2,swap;

    while(scanf("%d %d",&a,&b)==2) {
        u0 = 1,u1 = 0;
        v0 = 0,v1 = 1;

        r = a%b;
        q = a/b;

        while(r>0) {
            a = b;
            b = r;
            r = a%b;
            u2 = u0-q*u1;
            v2 = v0-q*v1;
            u0 = u1;
            v0 = v1;
            u1 = u2;
            v1 = v2;
            q = a/b;
        }
        printf("%d %d %d\n",u1,v1,b);
    }
    return 0;
}
