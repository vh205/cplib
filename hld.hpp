const int maxN = 2e5 + 5;
vector<int> adj[maxN];
int N, sz[maxN], pa[maxN], head[maxN], hld[maxN], pos[maxN], nxt;

void DFS(int u) {
    sz[u] = 1;
    int mx = -1;
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == pa[u]) continue;
        DFS(v);
        if (mx == -1 || sz[adj[u][mx]] < sz[adj[u][i]]) mx = i;
        sz[u] += sz[v];
    }
    if (mx != -1) swap(adj[u][0], adj[u][mx]);
}

void HLD(int u) {
    pos[u] = ++nxt;
    for (auto &v : adj[u]) {
        if (v == pa[u]) continue;
        if (sz[u] <= sz[v] * 2) {
            hld[v] = hld[u];
            head[v] = head[u];
        }
        else {
            hld[v] = hld[u] + 1;
            head[v] = v;
        }
        HLD(v);
    }
}

void go(int u, int v, int d) {
    while (head[u] != head[v]) {
        if (hld[u] < hld[v]) swap(u, v);
        u = pa[head[u]];

    }
    if (pos[u] > pos[v]) swap(u, v);

}
