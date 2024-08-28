#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#fastio ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
const int MOD = 1009;
const int MAX = 2e5 + 7;


int main() {
    fastio;
    
    return 0;
}

vector<int> kmp(const string &s) {
    int n = s.size();
    vector<int> p(n);
    rep(i, 1, n) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}
