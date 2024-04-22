#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back
const int MOD = 1009;
const int MAX = 4e5 + 7;

/* 
O tamanho maximo de uma segtree deve ser declarado como 4*tamano maximo do array pois é o maximo que ela pode crescer
build - constroi a segtree. o Id da raiz deve ser inciado como 1
update - deve ser utilizado (1,0,sz-1, ldesejado, rdesejado -1)
query msm coisa
*/

ll sgtr[MAX];
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