#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;

typedef complex<double> C;
typedef vector<double> vd;
typedef vector<int> vi;
typedef vector<ll> vl;

void fft(vector<C> &a)
{
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1); // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2)
    {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vi rev(n);
    rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            rep(j, 0, k)
            {
                // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
                auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k]; /// exclude-line
                C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);  /// exclude-line
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
}

vi conv(const vi &a, const vi &b)
{
    if (a.empty() || b.empty())
        return {};
    vi res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz(res.size()), n = 1 << L;
    vector<C> in(n), out(n);

    copy(a.begin(), a.end(), in.begin());
    rep(i, 0, b.size()) in[i].imag(b[i]);

    fft(in);
    for (C &x : in)
        x *= x;
    rep(i, 0, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i, 0, res.size()) res[i] = imag(out[i]) / (4 * n);
    return res;
}

template <int M>
vd convMod(const vd &a, const vd &b)
{
    if (a.empty() || b.empty())
        return {};
    vd res(a.size() + b.size() - 1);
    int B = 32 - __builtin_clz(res.size()), n = 1 << B, cut = int(sqrt(M));
    vector<C> L(n), R(n), outs(n), outl(n);
    rep(i, 0, a.size()) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
    rep(i, 0, b.size()) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);
    rep(i, 0, n)
    {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    rep(i, 0, res.size())
    {
        ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
        ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}

const int MOD = 1009;
const int MAX = 2e5 + 3;
vd freq[MAX];

priority_queue<pair<int, vd>> f;

void resolve()
{
    int n, m, k;
    cin >> n >> m >> k;

    rep(i, 1, m + 1)
    {
        freq[i].push_back(1);
    }

    rep(i, 0, n)
    {
        int cor;
        cin >> cor;
        freq[cor].push_back(1);
    }

    rep(i, 1, n + 1)
    {
        if (!freq[i].empty())
            f.push(make_pair(-freq[i].size(), freq[i]));
    }

    vd aux;

    while (true)
    {
        if (f.size() == 1) break;

        ll t1 = f.top().first;
        vd fr1 = f.top().second;
        f.pop();

        ll t2 = f.top().first;
        vd fr2 = f.top().second;
        f.pop();

        aux = convMod<MOD>(fr1, fr2);

        f.push({-aux.size(), aux});
    }

    ll t = f.top().first;
    vd v = f.top().second;
    f.pop();
    cout << v[k] << "\n";

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    resolve();
    return 0;
}