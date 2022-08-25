template<class T> struct lazy_segment_tree {
	T base = 0;
	T comb(T a, T b) { return max(a, b); }
 
	int n; 
	vector<T> sg, lz; 
 
	lazy_segment_tree(int _n) { 
		init(_n);
	}
 
	void init(int _n) {
		n = _n;
		sg.assign(4 * n + 1, base);
		lz.assign(4 * n + 1, base);
	}

    void push(int id) {
        lz[id * 2] += lz[id];
        sg[id * 2] += lz[id];
        lz[id * 2 + 1] += lz[id];
        sg[id * 2 + 1] += lz[id];
        lz[id] = 0;
    }
 
	void update(int L, int R, T x) { update(L, R, x, 1, 1, n); }
 
	void update(int L, int R, T x, int id, int l, int r) {
        if (r < L || R < l) return;
        if (L <= l && r <= R) {
            lz[id] += x;
            sg[id] += x;
            return;
        }
 
		int m = (l + r) / 2;
        push(id);
		update(L, R, x, id * 2, l, m);
		update(L, R, x, id * 2 + 1, m + 1, r);

		sg[id] = comb(sg[id * 2], sg[id * 2 + 1]); 
	}
 
	T query(int L, int R) { return query(L, R, 1, 1, n); }
 
	T query(int L, int R, int id, int l, int r) {
		if (L <= l && r <= R) return sg[id];
		if (R < l || L > r) return base; 
 
		int m = (l + r) / 2;
        push(id);
		return comb(query(L, R, id * 2, l, m), query(L, R, id * 2 + 1, m + 1, r)); 
	}
};