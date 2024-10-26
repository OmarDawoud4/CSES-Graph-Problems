#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vi>

const int INF = INT_MAX;

int n, m;
vvi adj;
int p[100001];
bool visited[100001];

void bfs(int s, int e) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    p[s] = -1;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                p[neighbor] = node;
                q.push(neighbor);
                
                if (neighbor == e) return;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    
    adj.assign(n + 1, vi());
    memset(visited, false, sizeof(visited));
    memset(p, -1, sizeof(p));
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bfs(1, n);
    
    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> path;
        for (int v = n; v != -1; v = p[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        
        cout << path.size() << "\n";
        for (int v : path) {
            cout << v << " ";
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
