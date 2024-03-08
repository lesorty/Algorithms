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

pair<ll,ll> seg[4*maxn];
ll n,m;

pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first < b.first) return a;
    if(a.first > b.first) return b;

    return make_pair(a.first, a.second+b.second);
}


void build(ll a[], ll id, ll l, ll r){
    if(l == r) seg[id] = {a[l],1};
    else{
        ll mid = (l+r)/2;
        build(a,2*id,l,mid);
        build(a,2*id+1,mid+1,r);
        seg[id] = combine(seg[id*2], seg[id*2+1]);
    }
}

void build(ll arr[]) {
    build(arr, 1,0,n-1);
}


pair<ll,ll> query(ll id, ll segl, ll segr, ll l, ll r){
    if(segl > r || segr < l) return {LONG_LONG_MAX, 0};
    if(segr <= r && segl >= l) return seg[id];

    ll mid = (segl+segr) / 2;
    pair<ll,ll> leftside = query(2*id, segl, mid, l,r);
    pair<ll,ll> rightside = query(2*id+1, mid+1, segr, l, r);
    
    return combine(leftside, rightside);   
}

pair<ll,ll> query(ll l, ll r){
    return query(1,0,n-1, l, r-1);
}

void update(ll id, ll l, ll r, ll pos, ll newv){
    if(l == r) {seg[id] = {newv,1}; return;}

    ll mid = (l + r) / 2;
    if(pos <= mid) update(id*2, l, mid, pos, newv);
    else update(2*id+1, mid+1, r, pos, newv);

    seg[id] = combine(seg[id*2], seg[2*id+1]);
}

void update(ll pos, ll newv){
    update(1,0,n-1, pos, newv);
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

            update(idx,v);
        }

        if(type == 2){
            ll l, r; cin >> l >> r;

            pair<ll,ll> out = query(l,r);
            cout << out.first << " " << out.second << endl;
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