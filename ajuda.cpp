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

vector<vector<char>> matrix; 
bool flag;

void dfs(vector<vector<bool>>& vis,vector<pair<ll,ll>>& nodes, ll x, ll y, ll dx, ll dy){
    if((x+dx > 0) && (x+dx < vis.size())){
        if((y+dy > 0) && y+dy < vis[0].size()){
            // cout << "dx " << dx << " dy " << dy << endl;
            // cout << x+dx << " " << y+dy << " node " << matrix[x+dx][y] << endl;
            if(matrix[x+dx][y+dy] != '*' && !vis[x+dx][y+dy]){
                // cout << "Node " << x << " " << y << " entrou não é um *" << endl;
                vis[x+dx][y+dy] = true;
                nodes.pb({x+dx,y+dy});
                dfs(vis, nodes, (x+dx), (y+dy), dx, dy);
            }
        }
    }  
}

int main(){
    
}
 