#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back

int const MAX = 2e5 + 7;
int arr[MAX];
int n,p;
int contapizza(int k){
    int total = 0;
    rep(i,0,n) total += (k/arr[i]);

    return total;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    cin >> n >> p;
    rep(i,0,n) cin >> arr[i];

    int l = 0;
    int r = 1e18;
    int out = 0;
    while(l <= r){
        int mid = (l+r)/2;

        if(contapizza(mid) >= p){r = mid-1; out = mid;}
        else l = mid + 1;
    }

    cout << out << endl;
    return 0;
}
