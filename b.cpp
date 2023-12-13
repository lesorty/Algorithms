    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define vll vector<long long>
    #define pb push_back
    #define endl "\n"
    #define rep(i, a, b) for(ll i = (a); i < (b); i++)
    #define sorta(arr) sort((arr).begin(), (arr).end())
    #define sz(x) x.size()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--){
        ll n, c; cin >> n >> c;
        ll arr[n];
        rep(i,0,n) cin >> arr[i];
        ll l = 0;
        ll r = 1e9;

        while(l <= r){
            ll m = (l + r)/ 2;
            ll soma = 0;

            rep(i,0,n){
                ll cur = arr[i]+ (2 * m);
                soma += cur * cur;  
                if(soma > c) break;
            }

            if(soma > c) r = m -1; 
            else l = m + 1;
        }
        cout << r << endl;
    }

    return 0;
}
