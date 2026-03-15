#include <bits/stdc++.h>

using namespace std;

string s, pattern;
const int MAXSIZE = 1e5 + 1;

int lps[MAXSIZE];

void build_lps(){
    int m = pattern.size();
    lps[0] = 0;
    int len = 0, i = 1;
    while (i < m){
        if (pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        } else if (!len){
            lps[i] = 0;
            i++;
        } else {
            len = lps[len - 1];
        }
    }
}

vector <int> indices;

void kmp_indices(){
    int m = s.size();
    int i = 0, j = 0;
    while(i < m){
        if(s[i] == pattern[j]){
            i++;
            j++;
            if(j == pattern.size()){
                indices.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if (j > 0){
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main(){
    cin >> s >> pattern;
    build_lps();
    kmp_indices();
    for(int a : indices) cout << a << " ";

}