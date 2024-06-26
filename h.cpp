#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
const int NN = 2e6 + 1, K = 2, P = uniform_int_distribution<int>(256, 1e9)(rng); // l > |sigma|, r < min(mod)
const ll MOD[] = {1000893493, 1013782387};
ll ph[NN][K], hh[NN][K], IT; // LEMBRAR DE CHAMAR pre()!!!!!!!!!!
void pre() { rep(i, 0, NN) rep(j, 0, K) ph[i][j] = i ? ph[i - 1][j] * P % MOD[j] : 1; }

struct hsh {
    int L;
    hsh() {}
    hsh(const string &s) {
        L = IT, IT += sz(s);
        rep(i, 0, sz(s)) rep(j, 0, K) {
            hh[L + i][j] = ((i > 0 ? hh[L + i - 1][j] * P : 0) + s[i]) % MOD[j];
        }
    }
    array<ll, K> operator()(int l, int r) {
        array<ll, K> ans;
        rep(j, 0, K) {
            ans[j] = hh[L + r][j] - (l > 0 ? hh[L + l - 1][j] * ph[r - l + 1][j] % MOD[j] : 0);
            if (ans[j] < 0) ans[j] += MOD[j];
        }
        return ans;
    }
};

int main(){
    pre();
    string word;
    cin >> word;
    
    string small;
    cin >> small;

    if (small.size() > word.size()){
        cout << 0 << endl;
        return 0;
    }

    hsh hashbig(word);
    hsh hashsmall(small);

    int ans = 0;
    for (int i = 0; i <= word.size() - small.size()+1; i++){
        if (hashbig(i, i+small.size()-1) == hashsmall(0, small.size()-1)){
            ans+=1;
        }
    }
    cout << ans;


}