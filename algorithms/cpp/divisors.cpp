#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())
#define sz(x) x.size()

vector<ll> divs;

void findivisors(ll n){
    for(ll i = 1; i * i <= n; i++){
        if(n % i) continue;
        divs.pb(i);
        if(n / i != i) divs.pb(n / i);
    }
}