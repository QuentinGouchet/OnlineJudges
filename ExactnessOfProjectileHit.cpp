#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
double ans;

struct Point  {
    double x, y;
    void input() { scanf("%lf %lf",&x,&y); }
};
typedef struct Point Point;

Point p[105], t;

int polynom() {
    int i,j,c = 0;
    for(i=1,j=n;i<=n;j=i++) {
        if (((p[i].y>p[0].y)!=(p[j].y>p[0].y)) && (p[0].x<(p[j].x-p[i].x)*(p[0].y-p[i].y)/(p[j].y-p[i].y)+p[i].x))
            c = !c;
    }
    return c;
}

double vect_product (Point O,Point P,Point Q) {
    return ((P.x-O.x)*(Q.y-O.y)-(P.y-O.y)*(Q.x-O.x));
}

double dist(Point P,Point Q) {
    return sqrt((Q.x-P.x)*(Q.x-P.x)+(Q.y-P.y)*(Q.y-P.y));
}

bool inRange(Point A, Point B) {
    double ijx = B.x-A.x, ijy = B.y-A.y;
    double ix = p[0].x-A.x, iy = p[0].y-A.y;
    double jx = p[0].x-B.x, jy = p[0].y-B.y;
    return (ijx*ix+ijy*iy>0 && ijx*jx+ijy*jy<0);
}

double height(Point O,Point A,Point B) {
    if(!inRange(A,B))
        return min(dist(A,O),dist(B,O));
    else
        return fabs(vect_product(O,A,B)/dist(A,B));
}

int main() {
    p[0].input();

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        p[i].input();

    if (polynom())
        printf("0.000");
    else {
        ans = 10000.0;
        for(int i=1;i<=n;i++)
            ans = min(ans,height(p[0],p[i],p[i==n?1:(i+1)]));
        printf("%.3lf\n",2*ans);
    }
}
