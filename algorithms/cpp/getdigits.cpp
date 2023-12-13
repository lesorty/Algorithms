#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())
#define sz(x) x.size()

vector<ll> digits;
void getdigits(ll x)
{
    while(x){
        ll temp = x % 10;
        digits.pb(temp);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());

}

int main() {
    ll x; cin >> x;

    getdigits(x);
    rep(i,0,sz(digits)) cout << digits[i] << " ";
}