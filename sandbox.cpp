#include <bits/stdc++.h>
using namespace std;
//t2
#define ll long long
#define vll vector<long long>
#define mll map<long, long>
#define pb push_back
#define endl "\n"

bool usados[10] = {false};
ll soma = 0;
ll k;
bool flag = false;
vector<ll> ans;

void solve(vector<ll> &arr, ll ni,ll ai){
    soma += arr[ni]*ai;
    if(soma > k) {
        // cout << "soma maior" << endl;
        soma -= arr[ni]*ai;
        return;
        }
    // cout << "entrou no solve " << ni << " " << ai << endl << endl;
    usados[ai] = true;
    if(ai == 9){
        if(soma == k){
            // cout << "achou a soma" << endl;
            flag = true;
            ans.pb(ai);
        }
        soma -= arr[ni]*ai;
        usados[ai] = false;
        return;
    }
    for (ll i = 0; i < 10; i++) {
        if(!usados[i]) solve(arr, ni+1, i);
        if(flag){
            ans.pb(i);
            usados[ai] = false;
            return;
        }
    }
    soma -= arr[ni]*ai;
    usados[ai] = false;
    return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ntc; cin >> ntc;
    while(ntc--){
        flag = false;
        ans.clear();
        vector<ll> arr(10);
        for (ll i = 0; i < 10; i++) cin >> arr[i];
        cin >> k;

        ans.pb(0);
        for (ll i = 0; i < 10; i++) {
            if(!flag){
                solve(arr, 0,i);
                if(flag) ans[0] = i;
            }
        }
        if(flag) for (ll i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        else cout << -1;
        cout << endl;

    }
    return 0;
}