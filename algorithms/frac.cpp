#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)

const int MOD = 1e9+7 ;
const int MAX = 2e5 + 7;
const int INF = 1e9+7;

struct frac {
    ll num, den;
    frac() : num(0), den(1) {}
    frac(ll x) : num(x), den(1) {}
    frac(ll x, ll y) : num(x), den(y) {norm();}
    void norm() {
        if (den < 0) num = -num, den = -den;
        ll g = __gcd(abs(num), den);
        num /= g, den /= g;
    }
    frac& operator += (frac o) {
        num = num * o.den + o.num * den, den = den * o.den;
        norm();
        return *this;
    }
    frac& operator -= (frac o) {
        num = num * o.den - o.num * den, den = den * o.den;
        norm();
        return *this;
    }
    frac& operator *= (frac o) {
        num = num * o.num, den = den * o.den;
        norm();
        return *this;
    }
    frac& operator /= (frac o) {
        num = num * o.den, den = den * o.num;
        norm();
        return *this;
    }
    bool operator < (frac o) const { return num * o.den < den * o.num; }
    bool operator > (frac o) const { return num * o.den > den * o.num; }
    bool operator == (frac o) const { return num * o.den == den * o.num; }
    bool operator <= (frac o) const { return num * o.den <= den * o.num; }
    frac operator + (frac o) const { return frac(*this) += o; }
    frac operator - (frac o) const { return frac(*this) -= o; }
    frac operator * (frac o) const { return frac(*this) *= o; }
    frac operator / (frac o) const { return frac(*this) /= o; }
    string tos() { return to_string(num) + "/" + to_string(den); }
};
