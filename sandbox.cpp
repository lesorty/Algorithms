#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())
#define fastio ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define all(x) (x).begin(), (x).end() 
ll const mod = 1e9 + 7;
ll const MAX = 2e5+7;

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
    ll n,k; cin >> n >> k;
    ll arr[n];
    arr[0];
    ll soma = 1;
    ll resto = k-1;
    ll conta = 1;
    while(binpow(2,conta) <= resto && ){
        arr[conta] = binpow(2,conta);
        resto -= arr[conta];
        conta++;
    }


}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}