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

void factor(ll n, set<ll> &s, ll r){
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            ll a = i, b = n/i;

            ll fac1 = (a+2)/2, fac2 = (b+2)/2;
            if(a % 2 == 0 && fac1 > 1 && fac1 >= r) s.insert(fac1);
            if(b % 2 == 0 && fac2 > 1 && fac2 >= r) s.insert(fac2);
        }

    }
}


void solve(){
    ll n, x; cin >> n >> x;

    set<ll> s;

    factor(n-x, s, x);
    factor(n+x-2, s , x);

    cout << s.size() << endl;

}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    ll t; cin >> t;

    while(t--) solve();

    return 0;
}
