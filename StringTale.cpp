ye#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N;

int fill_P (string u,vector<int> &P) {
    P[0] = 0;
    P[1] = 0;
    for(int i=2;i<u.length();i++) {
        int a = P[i-1];
        while(a>0 && u[a]!=u[i-1])
            a = P[a];
        if(u[a]==u[i-1])
            P[i] = a+1;
        else
            P[i] = 0;
    }
    return 0;
}

vector<int> fill_matched (string u,string v,vector<int> P) {
    vector<int> matched(v.length(),0);
    matched[0] = 0;
    for(int i=1;i<v.length();i++) {
        int a = matched[i-1];
        while(a>0 && u[a]!=v[i-1])
            a = P[a];
        if(u[a]==v[i-1])
            matched[i] = a+1;
        else
            matched[i] = 0;
    }
    /*for(int i=0;i<matched.size();i++) {
        cout << matched[i];
    }
    cout << endl;*/
    return matched;
}

int main()
{
    cin >> N;

    vector<int> P(2*N,0);

    string input;
    string output;

    cin >> input;
    cin >> output;

    if(input.compare(output)==0){
        cout << 0 << endl;
        return 0;
    }

    if(input.length()!=output.length()) {
        cout << -1 << endl;
        return 0;
    }

    output += output;

    fill_P(input,P);

    vector<int> match = fill_matched(input,output,P);

    int i = 0;
    while(match[i]!=N && i<2*N)
        i++;

    if(i==2*N)
        cout << -1 << endl;
    else
        cout << i-N << endl;

    return 0;
}
