#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int INF = INT_MAX;
const long long LLINF = LLONG_MAX;

int n, m;
vector<vector<int>> adj;
vector<int> color;
vector<int> result;
bool hasCycle = false;

void dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            dfs(u);
        } else if (color[u] == 1) {
            hasCycle = true;
        }
    }
    color[v] = 2;
    result.push_back(v);
}

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    color.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    if (hasCycle) {
        cout << "IMPOSSIBLE\n";
    } else {
        reverse(result.begin(), result.end());
        for (int course : result) {
            cout << course << " ";
        }
        cout << "\n";
    }
}

int main() {
    fastio;
    int tc = 1;
    while (tc--) {
        solve();
    }
}
