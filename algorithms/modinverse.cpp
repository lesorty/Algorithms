#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())

ll binpow(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll modDivide(ll a, ll b, ll m){
    a = a % m;
    ll inv = binpow(b, m -2 , m);
    return (inv*a) % m;
}