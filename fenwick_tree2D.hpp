template<class T> struct fenwick_tree2D {
    vector<vector<T>> bit;
    int n, m;
	 
	fenwick_tree2D(int _n, int _m) {
		init(_n, _m);
    }

    void init(int _n, int _m) {
       	n = _n, m = _m;
	  	bit.resize(n);
	  	for (auto &x : bit) {
			x.assign(m, 0);
	  	}
   	}
         

	fenwick_tree2D(vector<vector<int>> a) : fenwick_tree2D(a.size(), a[0].size()) {
		for (int i = 0; i < (int)a.size(); ++i) {
			for (int j = 0; j < (int)a[0].size(); ++j) {
				add(i, j, a[i][j]);
			}
		}
	}

    T sum(int x, int y) {
        T ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

	T sum(int x1, int y1, int x2, int y2) {
		return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
	}

    void add(int x, int y, T d) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += d;
    }
};
