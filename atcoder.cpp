#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
const int MOD = 1009;
const int MAX = 107;

void solve(){
    ll n;cin >> n;
    ll arr[MAX] = {0};
    rep(i,0,n) {
        ll x; cin >> x;
        arr[x]++;
    }

    ll out = 0;
    rep(i,0,MAX){
        out += arr[i]/3;
    }
    cout << out << endl;

}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    
    return 0;
}
