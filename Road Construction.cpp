#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
struct DSU {
    vector<int> parent, size;
    int components;

    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int get_root(int x) {
        if (parent[x] != x) {
            parent[x] = get_root(parent[x]);
        }
        return parent[x];
    }

    void merge(int u, int v) {
        int u_root = get_root(u);
        int v_root = get_root(v);
        if (u_root != v_root) {
            if (size[u_root] >= size[v_root]) {
                parent[v_root] = u_root;
                size[u_root] += size[v_root];
            } else {
                parent[u_root] = v_root;
                size[v_root] += size[u_root];
            }
            components--;
        }
    }

    int set_size(int x) {
        return size[get_root(x)];
    }

    int get_components() {
        return components;
    }

    bool same_set(int u, int v) {
        return (get_root(u) == get_root(v));
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    int mx = 1;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dsu.merge(x, y);
        mx = max(mx, dsu.set_size(x));
        int comp_cnt = dsu.get_components();
        cout << comp_cnt << " " << mx << endl;
    }
}

int main() {
   fastio
    int tc = 1 ;
  cin>>tc;
  while (tc--){
    solve();
    }
  
}
