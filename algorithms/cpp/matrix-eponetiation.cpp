#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())
#define sz(x) x.size()
#define fastio ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define all(x) (x).begin(), (x).end() 
ll const mod = 1e9 + 7;
ll const MAX = 107;

template<typename T, int N> struct matrix {
    array<array<T, N>, N> a{};
    matrix operator * (const matrix &o) const {
        matrix ans;
        rep(i, 0, N) rep(j, 0, N) rep(k, 0, N)
            ans.a[i][j] += a[i][k] * o.a[k][j];
        return ans;
    }
    matrix operator ^ (ll e) const {
        matrix ans, self(*this);
        rep(i, 0, N) ans.a[i][i] = 1;
        while (e > 0) {
            if (e & 1) ans = ans * self;
            self = self * self;
            e >>= 1;
        }
        return ans;
    }
    vector<T> operator * (const vector<T> &o) const {
        vector<T> ans(N);
        rep(i, 0, N) rep(j, 0, N) ans[i] += a[i][j] * o[j];
        return ans;
    }
};

bool can(ll i, ll j){
    return(i >= 0 && i < 8 && j >= 0 && j < 8);
}


int main(){
    fastio;

    unsigned int k; cin >> k;
    matrix<unsigned int,65> grid;

    rep(i,0,65) grid.a[i][64]++;

    rep(i,0,8){
        rep(j,0,8){
            ll cur = 8*i+j;
            if(can(i+2, j+1)) grid.a[cur][8*(i+2)+j+1]++;
            if(can(i+1,j+2)) grid.a[cur][8*(i+1)+j+2]++;
            if(can(i+2,j-1)) grid.a[cur][8*(i+2)+j-1]++;
            if(can(i+1,j-2)) grid.a[cur][8*(i+1)+j-2]++;
            if(can(i-1,j+2)) grid.a[cur][8*(i-1)+j+2]++;
            if(can(i-2,j+1)) grid.a[cur][8*(i-2)+j+1]++;
            if(can(i-2,j-1)) grid.a[cur][8*(i-2)+j-1]++;
            if(can(i-1,j-2)) grid.a[cur][8*(i-1)+j-2]++;
        }
    }

    grid = grid ^ (k+1);
    unsigned int out = grid.a[0][64];

    cout << out << endl;
    return 0;
}