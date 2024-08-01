#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
#define print(x) cout << x << endl
#define sz(x) x.size()
#define input(x) cin >> x

const int MOD = 1009;
const int MAX = 2e5 + 7;

template<typename T> struct bit {
    int n;
    vector<vector<T>> a;
    bit (int n) : n(n), a(n + 1, vector<T>(n + 1)) {}
    void add(int i, int j, T val) {
        for (; i <= n; i += i & -i) {
            for (int pos = j; pos <= n; pos += pos & -pos) {
                a[i][pos] += val;
            }
        }
    }
    T query(int i, int j) {
        T ans = 0;
        for (; i > 0; i -= i & -i) {
            for (int pos = j; pos > 0; pos -= pos & -pos) {
                ans += a[i][pos];
            }
        }
        return ans;
    }
};

void solve() {
    ll n; cin >> n;

    bit<ll> bt(n);
    
    while(true){
        string op; cin >> op;


        if(op == "END")return;
        else if(op == "SET"){
            ll x,y, val; cin >> x >> y >> val;
            x++;y++;
            ll cur = bt.query(x,y) - bt.query(x-1,y) - bt.query(x,y-1) + bt.query(x-1,y-1);
            bt.add(x,y,-cur);
            bt.add(x,y,val);
        }

        if(op == "SUM"){
            ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            x1++;y1++;x2++;y2++;
            ll sum = bt.query(x2,y2) - bt.query(x1-1,y2) - bt.query(x2,y1-1) + bt.query(x1-1,y1-1);
            cout << sum << endl;
        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}