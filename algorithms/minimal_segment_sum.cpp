#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
ll const mod = 1e9 + 7;
ll const maxn = 1e5;

struct node {
    ll sum, pref, suff, ans;
};

node seg[4*maxn];
ll n, m;


node combine(node l, node r) {
    node res;
    res.sum = l.sum + r.sum;
    res.pref = min(l.pref, l.sum + r.pref);
    res.suff = min(r.suff, r.sum + l.suff);
    res.ans = min(min(l.ans, r.ans), l.suff + r.pref);
    return res;
}

node make_node(ll val){
    node out;
    out.sum = val;
    out.pref = out.suff = out.ans = val;
    return out;
}

void build(ll arr[], ll id, ll l , ll r){
    if(l == r) {seg[id] = make_node(arr[l]); return;}

    ll mid = (l + r) / 2;

    build(arr, 2*id, l, mid);
    build(arr, 2*id+1, mid+1, r);
    seg[id] = combine(seg[2*id], seg[2*id+1]);
}

void build(ll arr[]) {
    build(arr, 1,0,n-1);
}

void update(ll id, ll l, ll r, ll pos, ll newv){
    if(l == r){seg[id] = make_node(newv); return;}

    ll mid = (l + r) / 2;
    if(pos <= mid) update(2*id, l, mid, pos, newv);
    else update(2*id+1, mid+1, r, pos, newv);

    seg[id] = combine(seg[2*id], seg[2*id+1]);
}

void update(ll pos, ll newv){
    update(1,0,n-1, pos, newv);
}

node query(ll id, ll lt, ll rt, ll l, ll r){
    if(lt > r || rt < l) return make_node(1e9);
    if(rt <= r && lt >= l) return seg[id];

    ll mid = (lt+rt) / 2;
    node leftside = query(2*id, lt, mid, l,r);
    node rightside = query(2*id+1, mid+1, rt, l, r);
    
    return combine(leftside, rightside);
}

node query(ll l, ll r){
    return query(1,0,n-1, l, r);
}

void solve(){
    cin >> n >> m;
    ll arr[n];
    rep(i,0,n) cin >> arr[i];
    build(arr);

    rep(i,0,m){
        ll type; cin >> type;

        if(type == 1){
            ll idx, v; cin >> idx >> v;
            update(idx, v);
        }

        else if(type == 2){
            ll l, r; cin >> l >> r;
            cout << query(l,r-1).ans << endl;
        }
    }
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);
    
    solve();

    return 0;
}
