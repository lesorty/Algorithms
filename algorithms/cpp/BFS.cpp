// queue<ll> fila;
// fila.push(start_node);
// d[start_node] = 0;
// while(!fila.empty()){
//     ll topo = fila.front();
//     fila.pop();
//     for(auto c: adj[topo])){
//         if(d[c] <= d[topo] + 1) continue;
//         d[c] = d[topo] + 1;
//         fila.push(c);
//     }
// }