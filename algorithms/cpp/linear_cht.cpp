#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
ll const mod = 1e9 + 7;
ll const MAX = 107;// NÃO FUNCIONANDO.

struct line {
    ll a, b;
    ll eval(ll x) {
        return a * x + b;
    }
    long double inter(const line &oth) const {
        return (long double) (-b + oth.b) / (a - oth.a);
    }
};// NÃO FUNCIONANDO.

struct cht {
    deque<line> q;
    void add(ll a, ll b) {// NÃO FUNCIONANDO.
        line cur = { a, b };
        while (q.size() > 1) {
            if (q.back().a == a) {
                if (b <= q.back().b) return;
                q.pop_back();
                continue;
            }// NÃO FUNCIONANDO.
            if (cur.inter(q[q.size() - 1]) < cur.inter(q[q.size() - 2])) break;
            q.pop_back();
        }
        q.push_back(cur);
    }
    ll query(ll x) {
        while (q.size() > 1 && q[0].eval(x) <= q[1].eval(x)) q.pop_front();
        return q[0].eval(x);
    }
};


void solve(){
    // NÃO FUNCIONANDO.
    ll n,m; cin >> n >> m;
    vector<ll> a(n);// NÃO FUNCIONANDO.

    rep(i,0,n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    cht convex;
    for(ll i = n-1; i >= 0; i--){
        convex.add(i+1, (i+1)*a[i]);
    }   

    while(m--){
        ll c; cin >> c;
        cout << convex.query(c) << " ";// NÃO FUNCIONANDO.
    }
    cout << endl;
    
}
// NÃO FUNCIONANDO.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);// NÃO FUNCIONANDO.

    solve();

    return 0;// NÃO FUNCIONANDO.
}