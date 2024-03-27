#include <bits/stdc++.h>

using namespace std;

#define ll long long


const int MX = 2e5+10;

map<ll,ll> contaCor[MX];
vector<vector<ll>> lista_adj;
ll cor[MX];
ll res [MX];
ll freq[MX];

void  dfs(int vertice, int pai = -1){

    contaCor[vertice][cor[vertice]] = 1;
    freq[vertice] = 1;
    res[vertice] = cor[vertice];
    for(auto adj: lista_adj[vertice]){
        if(adj == pai) continue;
        
        dfs(adj, vertice);
        
        if(contaCor[adj].size() > contaCor[vertice].size()) {
            contaCor[vertice].swap(contaCor[adj]);
            freq[vertice] =  freq[adj];
            res[vertice] = res[adj];
        }
    }
    
    for(auto adj: lista_adj[vertice]){
        if(adj == pai) continue;
        
        for(auto cores: contaCor[adj]){
            // cores.first = valor da cor
            // cores.second = freq

            contaCor[vertice][cores.first] += cores.second;
            if(freq[vertice] < contaCor[vertice][cores.first]){
                res[vertice] = cores.first; 
                freq[vertice] = contaCor[vertice][cores.first];
            }
            else if(contaCor[vertice][cores.first] == freq[vertice]){
                res[vertice] += cores.first; 
            }
        }
    } 
} 



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    lista_adj.assign(n+1, {});
    for(ll i = 1; i <= n; i++) contaCor[i].clear();
    for(ll i = 1; i <= n; i++) cin >> cor[i];

    for(ll i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        lista_adj[a].push_back(b);
        lista_adj[b].push_back(a);
    }
    dfs(1);

    for(auto item: res) if(item != 0) cout << item << " ";
    cout << endl;
    return 0;
}