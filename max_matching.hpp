struct max_match {
    int n, m, left[305];
    bool vis[305];
    vector<int> g[305];

    void init(int n, int m) {
        this->n = n, this->m = m;
        for (int i = 0; i <= n; ++i) {
            g[i].clear();
        }
        memset(left, -1, sizeof left);
    }

    bool match(int u) {
        for (auto &v : g[u]) {
            if (vis[v]) continue;
            vis[v] = 1;
            if (left[v] == -1 || match(left[v])) {
                left[v] = u;
                return true;
            }
        }
        return false;
    }

    int solve() {
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof vis);
            if (match(i)) ++ret;
        }
        return ret;
    }
};
