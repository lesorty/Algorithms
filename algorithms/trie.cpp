#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back

const int N = 1e6 + 10;
struct trie {
    trie() {}
    struct node {
        bool end;
        int ch[26];
		int tam[26];
        node() { memset(ch, -1, sizeof ch), end = false; memset(tam, 0, sizeof tam)}
    };
    node a[N];
    int head = 0;
    void insert(const string &s) {
        int cur = 0;
        rep(i, 0, sz(s)) {
            if (a[cur].ch[s[i] - 'a'] == -1) a[cur].ch[s[i] - 'a'] = ++head;
            cur = a[cur].ch[s[i] - 'a'];
        }
        a[cur].end = true;
    }

    ll veri(const string &s){
		 ll cur = 0;
		for(int i = 0; i < s.size(); i++){
			char c = s[i];
			if(a[cur].ch[c - 'a'] == -1) return 0;
			if(i != s.size() -1) cur = a[cur].ch[c-'a'];
		}
		ll out = a[cur].tam[s[s.size()-1] - 'a'];
		return out;
	}
} tr;

int main(){

	return 0;
}
