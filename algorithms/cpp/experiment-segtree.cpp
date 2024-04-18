#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back
const int MOD = 1009;
const int MAX = 4e5 + 7;

ll sgtr[MAX];

ll next2p(ll x){
    ll aux = 1;
    while(aux < x) aux <<= 1;
    return aux;
}

void itbuild(ll ax[], ll n){
    ll n2 = next2p(n);

    rep(i,0,n){
        sgtr[n2-1+i] = ax[i];
    }
    ll dif = n2 - n;
    rep(i,0,dif){
        sgtr[n2-1+n+i] = 0;
    }

    n2/=2;
    while(n2){
        rep(i,0,n2){
            ll pos = n2-1+i;
            sgtr[pos] = sgtr[2*pos+1] + sgtr[2*pos+2];
        }

        n2 /= 2;
    }
}

void build(ll arr[], ll id, ll l, ll r){
    if(l == r) sgtr[id] = arr[l];
    else{
        ll mid = (l+r)/ 2;  
        build(arr, id*2, l, mid);
        build(arr, id*2+1, mid+1, r);
        sgtr[id] = sgtr[id*2] + sgtr[id*2+1];
    }
}

void update(ll id, ll l, ll r, ll i, ll v){
    if(l == r) sgtr[id] = v;
    else{
        ll mid = (l+r)/2;
        if(mid >= i)
            update(id*2, l, mid, i, v);
                 
        else
            update(id*2+1,mid+1,r,i,v);

        sgtr[id] = sgtr[id*2] + sgtr[id*2+1];
    }
}   

ll query(ll id, ll l, ll r, ll dl, ll dr){
    if((r < dl) || (l > dr)) return 0;
    if(l >= dl && r <= dr) return sgtr[id];

    ll mid = (l+r)/2;
    return query(2*id, l, mid, dl, dr) + query(2*id+1, mid+1, r, dl, dr);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    ll n,m; cin >> n >> m;
    ll arr[n];
    rep(i,0,n) cin >> arr[i];

    build(arr,1,0,n-1);
    rep(i,0,m){
        ll x,a,b; cin >> x >> a >> b;

        if(x == 1){
            update(1,0,n-1,a,b);
        }

        if(x == 2){
            cout << query(1,0,n-1,a,b-1) << endl;
        }
    }
    
    return 0;
}