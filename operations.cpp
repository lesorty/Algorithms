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
        ll h;
        node() : x(0) {}
        node(ll x, ll h) : x(x), h(h) {}

        node operator + (const node &o) const {
            if(h % 2 == 0){
                return node((x | o.x), h+1);
            }
            else{
                return node((x ^ o.x), h+1);
            }
        }

    };
    int n;
    vector<node> tree;
    seg_tree(int n) : n(n), tree(n * 4) {}

    inline int left(int id) { return (id << 1); }
    inline int right(int id) { return (id << 1) | 1; }

    void build(int id, int l, int r, ll h){
    if(l == r) tree[id] = node(arr[l]);
    else{
        int mid = (l + r) >> 1;
        build(left(id),l,mid);
        build(right(id),mid+1,r);
        tree[id] = tree[left(id)]+tree[right(id)];  
        }
    }


    void update(int id, int l, int r, int pos, T val) {
        if (l == r) tree[id] = node(val);
        else {
            int mid = (l + r) >> 1;
            if (pos <= mid) update(left(id), l, mid, pos, val);
            else update(right(id), mid + 1, r, pos, val);
            tree[id] = tree[left(id)] + tree[right(id)];
        }
    }

    node query(int id, int l, int r, int lq, int rq) {
        if (l > rq || r < lq) return node();
        if (lq <= l && r <= rq) return tree[id];
        int mid = (l + r) >> 1;
        return query(left(id), l, mid, lq, rq) + query(right(id), mid + 1, r, lq, rq);
    }

    void update(int pos, T val) { update(1, 0, n - 1, pos, val); }
    node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
int main () {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    ll n,m; cin >> n >> m;
    ll tam = 1;
    rep(i,0,n) tam *= 2;

    seg_tree<ll> sgtr(tam);
    sgtr.build();

    arr.resize(tam);

    rep(i,0,m){
        ll x,y; cin >> x >> y;


    }


    return 0;
}