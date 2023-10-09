#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    // Inserindo elementos na priority_queue
    pq.push(30);
    pq.push(10);
    pq.push(50);

    // Acessando o valor no topo
    int valorNoTopo = pq.top();

    std::cout << "Valor no topo: " << valorNoTopo << std::endl;

    return 0;
}
