#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> bestSet, currentSet;
int bestSize = 0;

void branchAndBound(int v) {
    if (v == n) {
        if ((int)currentSet.size() > bestSize) {
            bestSize = currentSet.size();
            bestSet = currentSet;
        }
        return;
    }

    if (currentSet.size() + (n - v) <= bestSize)
        return;

    bool canInclude = true;
    for (int u : adj[v])
        if (find(currentSet.begin(), currentSet.end(), u) != currentSet.end())
            canInclude = false;

    if (canInclude) {
        currentSet.push_back(v);
        branchAndBound(v + 1);
        currentSet.pop_back();
    }

    branchAndBound(v + 1);
}

int main() {
    cin >> n >> m;
    adj.assign(n, {});

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    branchAndBound(0);

    cout << "Tamanho do Conjunto Independente Maximo: " << bestSize << endl;
    cout << "Vertices: ";
    for (int v : bestSet) cout << v << " ";
    cout << endl;

    return 0;
}
