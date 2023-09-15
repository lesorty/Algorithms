#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define endl "\n"

const ll MOD = 1e9 + 7;
  
ll binpow(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll b, ll m){
    ll g = __gcd(b, m);
    if(g != 1) return -1;
    else return binpow(b, m-2, m);
}

ll modDivide(ll a, ll b, ll m){
    a = a % m;
    ll inv = modInverse(b, m);
    if(inv == -1) return -1;
    else return (inv * a) % m;
}

int main(){
    ll modulo = 1000000007;
    ll t; cin >> t;
    vector<ll> factors;
    factors.push_back(1);
    ll fact = 1;

    for(ll i = 1; i < 1000007; i++){
        fact = (fact * i) % modulo;
        factors.push_back(fact);
    }
    ll i = 0;
    
    while(t--){
        ll n, k; cin >> n >> k;
        vector<ll> nums(n);
        for(ll i = 0; i < n; i++) {
            ll x; cin >> x;
            nums[i] = x % modulo;
        }
        sort(nums.begin(), nums.end());
        ll soma = 0;

        while(n >= k) {
            ll ocorrences = modDivide(factors[n-1],(((factors[k-1])*factors[(n - k)]))%modulo,modulo);
            soma = (soma + ((nums[n-1] * ocorrences)%modulo)) % modulo;
            n--;
        }
    
        i++;
        cout << "Case #" << i << ": " << soma << endl;
    }

    return 0;
}