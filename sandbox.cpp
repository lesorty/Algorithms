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

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0);     

    ll n; cin >> n;
    ll grau[n+1] = {0};
    
    rep(i,0,n-1){
        ll x,y; cin >> x >> y;
        grau[x]++;
        grau[y]++;
    }

    vector<ll> leafs;
    rep(i,1,n+1) if(grau[i] == 1) leafs.pb(i);

    cout << (sz(leafs)+1) / 2 << endl;

    rep(i,1,sz(leafs)){
        cout << leafs[i-1] << " " << leafs[i] << endl;
        if(i < (sz(leafs) - 2)) i++;
    }
    

    return 0;
}
