#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back

vector<ll> arr;

template<class T> struct seg_tree {
    struct node {
        T x;
        node() : x(0) {}
        node(T x) : x(x) {}
        node operator + (const node &o) const {
            return node(x + o.x);
        }
    };
    int n;
    vector<node> tree;
    vector<ll> lazy;
    seg_tree(int n) : n(n), tree(n * 4), lazy(n*4) {}
    

    inline int left(int id) { return (id << 1); }
    inline int right(int id) { return (id << 1) | 1; }

    void build(int id, int l, int r){
    if(l == r) tree[id] = node();
    else{
        int mid = (l + r) >> 1;
        build(left(id),l,mid);
        build(right(id),mid+1,r);
        tree[id] = tree[left(id)]+tree[right(id)];  
        }
    }

    void push(ll id, ll l, ll r){
        if(lazy[id]){
            tree[id] = tree[id] + node(lazy[id]*(r-l+1));
            if(l != r){
                lazy[left(id)] += lazy[id];
                lazy[right(id)] += lazy[id];
            }
        }
        lazy[id] = 0;
        return;
    }

    void update(int id, int l, int r, int ipos, int fpos, T val) {
        push(id, l, r);
        if(l > fpos || r < ipos) return;
        if (ipos <= l && r <= fpos)  {
            lazy[id] += val;
            push(id, l, r);
        }
        else {
            int mid = (l + r) >> 1;
            update(left(id), l, mid, ipos, fpos, val);
            update(right(id), mid + 1, r, ipos, fpos,  val);
            tree[id] = tree[left(id)] + tree[right(id)];
        }
    }

    node query(int id, int l, int r, int lq, int rq) {
        if (l > rq || r < lq) return node();
        push(id,l,r);
        if (lq <= l && r <= rq){
            return tree[id];
        } 
        int mid = (l + r) >> 1;
        return query(left(id), l, mid, lq, rq) + query(right(id), mid + 1, r, lq, rq);
    }

    void build() {build(1,0,n-1);}
    void update(int ipos, int fpos, T val) { update(1, 0, n - 1, ipos, fpos, val); }
    node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};


void solve(){
    ll n,c; cin >> n >> c;
    seg_tree<ll> sgtr(n);
    sgtr.build();

    rep(i,0,c){
        ll op; cin >>  op;

        if(op){
            ll p,q; cin >> p >> q;
            p--;q--;
            cout << sgtr.query(p,q).x << endl;
        }
        else{
            ll p,q, v; cin >> p >> q >> v;
            p--; q--;
            sgtr.update(p,q,v) ;
        }
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    ll t; cin >> t;    
    while(t--) solve();
    return 0;
}