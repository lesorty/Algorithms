#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())
#define sz(x) x.size()
#define fastio ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define all(x) (x).begin(), (x).end() 
ll const mod = 1e9 + 7;
ll const MAX = 107;

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
    // to make min queries, k = -k, m = -m, return -query(x)
};

void solventc(){
    ll n; cin >> n;
    vector<vector<ll>> retangulo(n, vector<ll>(3));
    rep(i,0,n){
        ll x,y,z; cin >> x >> y >> z;
        retangulo[i][0] = x; retangulo[i][1] = y; retangulo[i][2] = z;
    }
    sort(all(retangulo));

    LineContainer cht;
    cht.add(0,0);
    ll dp[n] = {0};

    rep(i,0,n){
        dp[i] = cht.query(retangulo[i][1]) + retangulo[i][0]*retangulo[i][1] - retangulo[i][2];
        cht.add(-retangulo[i][0], dp[i]);
    }

    ll out = 0;
    rep(i,0,n){
        out = max(out, dp[i]);
    }

    cout << out << endl;
}


int main(){
    fastio;

    // ll t; cin >> t;
    // while(t--) 
    solventc();

    return 0;
}