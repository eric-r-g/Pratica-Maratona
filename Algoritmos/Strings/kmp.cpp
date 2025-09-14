#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1e5;
int lps[MAXM];

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i < s2.size()){
        if(s2[i] == s2[len]){
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len == 0){
                lps[i] = 0;
                i++;
            } else {
                len = lps[len - 1];
            }
        }
    }
}