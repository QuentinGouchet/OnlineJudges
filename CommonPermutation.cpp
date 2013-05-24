#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define PB push_back

using namespace std;

int main()
{
    string a;
    string b;

    while(getline(cin,a) && getline(cin,b)) {
        vector<char> output;
        vector<int> usea(a.length(),1);
        vector<int> useb(b.length(),1);

        for(int i=0;i<a.length();i++) {
            for(int j=0;j<b.length();j++) {
                //printf("%c %c\n",a[i],b[j]);
                if(a[i]==b[j]) {
                    if(usea[i] && useb[j]) {
                        output.PB(a[i]);
                        usea[i] = 0;
                        useb[j] = 0;
                    }
                }
            }
        }

        sort(output.begin(),output.end());

        for(int i=0;i<output.size();i++)
            printf("%c",output[i]);
        printf("\n");
    }

    return 0;
}
