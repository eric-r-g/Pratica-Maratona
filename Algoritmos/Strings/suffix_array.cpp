#include <bits/stdc++.h>

using namespace std;

const int alfabeto = 256;

typedef pair <int, int> pii;

// ToDo: implementar junto com sparse table
struct suffix_array {
    string s;
    int n;

    vector <int> sa;
    vector <int> rank;
    vector <int> lcp;

    suffix_array(string s) : s(s + char(0)){
        n = this -> s.size();
        init_sa();
        init_lcp();
    }

    void init_sa(){
        sa = vector <int> (n), rank = vector <int> (n);
        vector <int> cnt(max(alfabeto, n));

        // passo 0 do processo

        // stable count sorting
        for(unsigned char c : s) cnt[c]++;
        for(int i = 1; i < alfabeto; i++)
            cnt[i] += cnt[i - 1];
        
        for(int i = 0; i < n; i++)
            sa[--cnt[s[i]]] = i;

        // calculo do rank
        rank[sa[0]] = 0;
        int classes = 0;
        for(int i = 1; i < n; i++){
            if(s[sa[i]] != s[sa[i - 1]]) classes++;
            rank[sa[i]] = classes;
        }
        classes++;

        vector <int> temp_sa(n), temp_rank(n);

        // passo k do processo
        for(int h = 0; (1 << h) < n; h++){
            for(int i = 0; i < n; i++){
                temp_sa[i] = sa[i] - (1 << h);
                if(temp_sa[i] < 0) temp_sa[i] += n;
            }

            fill(cnt.begin(), cnt.begin() + classes, 0);
            for(int i = 0; i < n; i++)
                cnt[rank[temp_sa[i]]]++;
            for(int i = 1; i < classes; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--)
                sa[--cnt[rank[temp_sa[i]]]] = temp_sa[i];

            temp_rank[sa[0]] = 0;
            classes = 0;
            for(int i = 1; i < n; i++){
                pii a = {rank[sa[i]], rank[(sa[i] + (1 << h)) % n]};
                pii b = {rank[sa[i - 1]], rank[(sa[i - 1] + (1 << h)) % n]};

                if(a != b) classes++;
                temp_rank[sa[i]] = classes;
            }
            classes++;
            rank.swap(temp_rank);
        }
    }

    void init_lcp(){
        lcp = vector <int> (n - 1);
        int k = 0;

        for(int i = 0; i < n; i++){
            if(rank[i] == n -1){
                k = 0;
                continue;
            }

            int j = sa[rank[i] + 1];
            while(i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            lcp[rank[i]] = k;
            if(k) k--;
        }
    }
};