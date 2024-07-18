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
    seg_tree(int n) : n(n), tree(n * 4) {}

    inline int left(int id) { return (id << 1); }
    inline int right(int id) { return (id << 1) | 1; }

    void build(int id, int l, int r){
    if(l == r) tree[id] = node(1);
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

    node query(int id, int l, int r, int target) {
        if(l == r) return node(l);
        int mid = (l + r) >> 1;
        if(tree[left(id)].x >= target) return query(left(id), l, mid, target);
        return query(right(id), mid + 1, r, target - tree[left(id)].x);
    }

    void build() {build(1,0,n-1);}
    void update(int pos, T val) { update(1, 0, n - 1, pos, val); }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
int main () {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    ll n; cin >> n;
    seg_tree<int> sgtr(n);
    sgtr.build();
    vector<ll> nums(n);
    rep(i,0,n) cin >> nums[i];

    rep(i,0,n){
        ll cur; cin >> cur;
        ll idx = sgtr.query(1,0,n-1,cur).x;

        cout << nums[idx] << " ";
    }

    return 0;
}