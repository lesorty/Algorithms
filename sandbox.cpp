#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back

template<class T> struct seg_tree {
    struct node {
        T open;
        T close;
        T seg;

        node() : {
            this->open = 0;
            this->close = 0;
            this->seg = 0;
        }
        node(Node nd) : {

        }
        node(T nopen, T nclose, T nseg) : {
            this->open = nopen;
            this->close = nclose;
            this->seg = nseg;
        }
        node operator + (const node &o) const {
            ll match = min(this->open, o.close);
            return node(o.open + (this->open-match), this->close + (o.close - match), this->seg + o.seg + 2*match);
        }
    };
    int n;
    vector<node> tree;
    seg_tree(int n) : n(n), tree(n * 4) {}

    inline int left(int id) { return (id << 1); }
    inline int right(int id) { return (id << 1) | 1; }

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

    string s; cin >> s;
    ll m; cin >> m;

    vector<ll[3]> nodes;
    rep(i,0,s.size()){  
        char c = s[i];
        if(c == '('){
            ll ar[3] = {1,0,0};
            nodes.pb(ar);
        }
        else{
            ll ar[3] = {0,1,0};
            nodes.pb(ar);
        }
    }

    seg_tree<ll> sgtr(nodes.size());

    rep(i,0,m){
        ll l,r; cin >> l >> r;

        
    }

    return 0;
}