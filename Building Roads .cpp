#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pii pair<int, int>

const int N = 1e5 + 5;
vi adj[N];
bool vis[N];

void DFS(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi sp;
    int cc = 0;

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            sp.push_back(i);
            DFS(i);
            cc++;
        }
    }

    cout << cc - 1 << endl;

    for (int i = 1; i < cc; ++i) {
        cout << sp[i - 1] << " " << sp[i] << endl;
    }
}

int main() {
    fastio

    int tc = 1;
  //cin>>tc;
    while (tc--) {
        solve();
    }

    return 0;
}
