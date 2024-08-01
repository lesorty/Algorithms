#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())
#define sz(x) x.size()
#define all(x) (arr).begin(), (arr).end()

vector<ll> squares;
void getsquares(ll x){
    rep(i,1,sqrt(x) + 2){
        if((i*i) <= x){
            squares.pb((i*i));
        }
    }
}

int main() {
    ll x ; cin >> x;
    getsquares(x);
    rep(i,0,sz(squares)) cout << squares[i] << " ";
}