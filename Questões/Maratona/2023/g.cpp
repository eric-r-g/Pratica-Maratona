#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define f first
#define s second

typedef long long int ll;

struct pt{
    int x, y;
    pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    pt operator-(const pt& o) const {return pt(x-o.x, y-o.y);}
};

bool operator<(const pt& a, const pt& b) {
    return (a.x != b.x ? a.x < b.x : a.y < b.y);
}

inline ll cross(const pt& a, const pt& b){
    return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

bool ccw(pt a, pt b, pt c) { return cross((b-a), (c-a)) >= 0; }

vector<pair<pt, int>> convex_hull(vector<pair<pt, int>> v){
    sort(v.begin(), v.end());
    vector<pair<pt, int>> l, u;

    for(int i = 0 ; i < v.size() ; i++){
        while(l.size() > 1 and !ccw(l.end()[-2].f, l.end()[-1].f, v[i].f))
            l.pop_back();
        l.push_back(v[i]);
    }
    for(int i = v.size()-1 ; i >= 0 ; i--){
        while(u.size() > 1 and !ccw(u.end()[-2].f, u.end()[-1].f, v[i].f))
            u.pop_back();
        u.push_back(v[i]);
    }
    l.pop_back(); u.pop_back();
    for(pair<pt, int> i : u) l.push_back(i);
    return l;
}

int main(){ _
    int n; cin >> n;

    vector<pair<pt, int>> v;
    for(int i = 1 ; i <= n ; i++){
        int x, y; cin >> x >> y;
        v.push_back({pt(x, y), i});
    }
    vector<pair<pt, int>> l = convex_hull(v);
    vector<int> ans;
    for(pair<pt, int> u : l){
        ans.push_back(u.s);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(int i = 0 ; i < ans.size() - 1 ; i++){
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << endl;
    return 0;
}