#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define ll long long

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char next_move[] = {'D', 'U', 'R', 'L'};
int n, m;
vector<string> grid;
vvi sp;
vector<vector<pii>> parent;
pii st, en;


bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#');
}


void BFS() {
    queue<pii> q;
    q.push(st);
    sp[st.first][st.second] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();


        for (int i = 0; i < 4; i++) {
            int xp = x + dx[i];
            int yp = y + dy[i];


            if (isValid(xp, yp) && sp[xp][yp] == -1) {
                sp[xp][yp] = sp[x][y] + 1;
                parent[xp][yp] = {x, y};
                q.push({xp, yp});


                if (xp == en.first && yp == en.second) {
                    string path;
                    pii cur = en;


                    while (cur != st) {
                        pii prev = parent[cur.first][cur.second];
                        for (int j = 0; j < 4; j++) {
                            if (prev.first + dx[j] == cur.first && prev.second + dy[j] == cur.second) {
                                path += next_move[j];
                                break;
                            }
                        }
                        cur = prev;
                    }
                    reverse(path.begin(), path.end());
                    cout << "YES" << endl;
                    cout << sp[en.first][en.second] << endl;
                    cout << path << endl;
                    return;
                }
            }
        }
    }

    cout << "NO" << endl;
}


void solve() {
    cin >> n >> m;
    grid.resize(n);
    sp.assign(n, vi(m, -1));
    parent.assign(n, vector<pii>(m, {-1, -1}));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                st = {i, j};
            } else if (grid[i][j] == 'B') {
                en = {i, j};
            }
        }
    }

    BFS();
}

int main() {
    fastio;
    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}
