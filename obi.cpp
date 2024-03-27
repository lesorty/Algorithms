#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int> > adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        FlowEdge e1(v, u, cap);
        FlowEdge e2(u, v, 0);
        edges.push_back(e1);
        edges.push_back(e2);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
        ll n, m, k; cin >> n >> m >> k;

        if(n == 0) break;
        ll faltaPt = (((n-1)*(n-2))/2); faltaPt *= m;
        ll pontuacao[n]; memset(pontuacao, 0, sizeof pontuacao);
        Dinic d(faltaPt+n+2, 0, faltaPt+n+1);
        ll qntpt = 0, qntptZ = 0;
        ll auxZero = (n-1)*m*2;
        queue<pair<ll,ll>> jogos;
        ll arestas[n][n];
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                arestas[i][j] = 0;
            }
        }

        for(ll i = 0; i < k; i++){
            ll a, b; char c;

            cin >> a >> c >> b;
            qntpt++;
            if(a == 0 || b == 0) {
                auxZero-=2;
            }
            else{
                qntptZ++;
                arestas[a][b]++;
                arestas[b][a]++;
            }
            if(c == '<'){
                pontuacao[b]+= 2;
            }
            else if(c == '>'){
                pontuacao[a]+= 2;
            }
            else{
                pontuacao[a] += 1; 
                pontuacao[b] += 1;
            }
        }
        ll capacidade = pontuacao[0]+auxZero;
        ll teste = faltaPt - qntptZ;
        ll flag = 0;

        for(ll i = 1; i < n; i++){
            for(ll j = 1; j < n; j++){
                if(i != j){
                    while(m-arestas[i][j]){
                        jogos.push({i, j});
                        arestas[i][j]++;
                        arestas[j][i]++;
                    }
                }
                
            }
        }
        ll res = 0;

        for(ll i = 1; i <= teste;i++){
            d.add_edge(0, i, 2);
        }

        for(ll i = 1; i < n; i++){
            if(capacidade-pontuacao[i]-1 < 0){
                flag = 1;   
                break;
            }
            d.add_edge(i+teste , faltaPt+n+1, capacidade-pontuacao[i]-1);    
            //cout <<"x " << capacidade-pontuacao[i]-1 << endl;

        }

        if(flag ){
            cout << "N" << endl; continue;
        }
        ll i = 1;
        //cout << faltaPt << endl;
        while(!jogos.empty()){
            ll a = jogos.front().first;
            ll b = jogos.front().second;
            jogos.pop();
            d.add_edge(i, a+teste, 2);
            d.add_edge(i, b+teste, 2); 
            i++;     
        }
    
        //for(ll i = 1; i < n; i++) cout << pontuacao[i] << endl;
        ll flow = d.flow();
        if(teste*2 > flow) cout << "N"<< endl;
        else cout << "Y" << endl;
        //cout<< flow << endl;

    }
    
    return 0;
}