#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
#define print(x) cout << x << endl
#define sz(x) x.size()
#define input(x) cin >> x
const int MOD = 1009;
const int MAX = 107;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll n; cin >> n;

    ll out = 0;
    rep(i,1,n+1){
        ll cur = sqrt(i);
        if(cur*cur == i) out = i;
    }
    cout << out;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    ll t = 1;
    while(t--) solve();
    return 0;
}
