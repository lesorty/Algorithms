    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define pll pair<long long, long long>
    #define vll vector<long long>
    #define pb push_back
    #define endl "\n"
    #define eb emplace_back  

    #include <bits/stdc++.h>
    using namespace std;




    bool isbipartide(vector<vector<ll>> adjacents, vector<ll> colors, ll start){
        queue<ll> fila;
        fila.emplace(start);
        colors[start] = 1;

        while(!fila.empty()){
            ll topo = fila.front();
            fila.pop();
            for(auto vis : adjacents[topo]){
                if(colors[vis] == colors[topo]) return false;
                else if(colors[vis] == 0) {
                    fila.emplace(vis);
                    colors[vis] = (colors[topo] == 1) ? 2 : 1;

                }
            }
        }
        for (ll i = 1; i < colors.size(); i++) {
            if(colors[i] == 0){
                if(!isbipartide(adjacents, colors, i)) return false;
            }
        }
        return true;
    }

    int main() {
        ll t; cin >> t;

        while(t--){
            ll n; cin >> n;
            vector<vector<ll>> adj(n+1);
            vector<ll> color(n+1);
            adj.assign(n+1,{});
            color.assign(n+1, 0);
            bool flag = false;

            for (ll i = 0; i < n; i++) {
                ll x, y; cin >> x >> y;
                if(x == y){
                    flag = true;
                }
                adj[x].pb(y);
                adj[y].pb(x);
            }

            if(flag) cout << "NO" << endl;
            else{
            string ans = (isbipartide(adj, color, 1) == true) ? "YES" : "NO";
            cout << ans << endl;
            }
        }

        return 0;
    }
