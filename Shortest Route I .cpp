#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
 
 
 
vector<vpi> adj;
vector<long long> dist;
vector<bool> vis;
int n ,m ;
void dijkstra(int start) {
 
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
 
    while (!pq.empty()) {
        auto [cost, curr] = pq.top();
        pq.pop();
 
 
        if (vis[curr]) continue;
        vis[curr] = true;
 
        for (auto [neighbor, weight] : adj[curr]) {
            if (!vis[neighbor] && dist[curr] + weight < dist[neighbor]) {
                dist[neighbor] = dist[curr] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}
 
void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    dist.assign(n + 1, LLONG_MAX);
    vis.assign(n + 1, false);
 
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
 
    dijkstra(1);
 
 
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}
 
int main() {
    fastio;
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
}
