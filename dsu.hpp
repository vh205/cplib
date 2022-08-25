struct dsu {
    vector<int> pa, sz;
    int comp = 0;

    dsu(int _n) {
	init(_n);
    }

    void init(int n) {
        pa.resize(n);
        iota(pa.begin(), pa.end(), 0);
        sz.assign(n, 1);
        comp = n;
    }

    int find(int x) {
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    }

    int size(int x) {
        return sz[find(x)];
    }

    bool unite(int x, int y) {
        if ((x = find(x)) == (y = find(y)))
            return false;

        if (sz[x] < sz[y]) swap(x, y);

        pa[y] = x;
        sz[x] += sz[y];
        comp--;
        return true;
    }
};
