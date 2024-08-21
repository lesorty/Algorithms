#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back
#define sz(x) x.size()

/*
PROBLEM LINK: https://www.spoj.com/problems/ADAINDEX/
Author: lesortey
date: 08/21/2024
*/

const int TRIESIZE = 1e6 + 10;
struct trie {
    trie() {}
    struct node {
        bool end;
        int ch[26];
		    int tam[26];
        node() { memset(ch, -1, sizeof ch), end = false; memset(tam, 0, sizeof tam);}
    };
    node a[TRIESIZE];
    int head = 0;
    void insert(const string &s) {
        int cur = 0;
        rep(i, 0, sz(s)) {
            if (a[cur].ch[s[i] - 'a'] == -1) {
              a[cur].ch[s[i] - 'a'] = ++head;
              a[cur].tam[s[i]-'a'] = 1;
            }
            else a[cur].tam[s[i]-'a']++;
            cur = a[cur].ch[s[i] - 'a'];
        }
        a[cur].end = true;
    }

    int veri(const string &s){
      int cur = 0;
		  for(int i = 0; i < s.size(); i++){
			  char c = s[i];
			  if(a[cur].ch[c - 'a'] == -1) return 0;
			  if(i != s.size() -1) cur = a[cur].ch[c-'a'];
		  }
		  int out = a[cur].tam[s[s.size()-1] - 'a'];
		  return out;
	 }
	 
} tr;

int main(){
  
  ll n, q; cin >> n >> q;
  
  while(n--){
    string s; cin >> s;
    tr.insert(s);
  }
  
  while(q--){
    string s; cin >> s;
    cout << tr.veri(s) << endl;
  }
  
  return 0;
}
