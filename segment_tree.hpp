template<class T> struct segment_tree {
	T base = inf; 
	T comb(T a, T b) { return min(a, b); }
 
	int n; 
	vector<T> sg; 
 
	segment_tree(int _n) { 
		init(_n);
	}
 
	void init(int _n) {
		n = _n;
		sg.assign(4 * n + 1, base);
	}
 
	void update(int i, T x) { update(i, x, 1, 1, n); }
 
	void update(int i, T x, int id, int l, int r) {
		if (l == r) { sg[id] = x; return; }
 
		int m = (l + r) / 2;
		if (i <= m) update(i, x, id * 2, l, m);
		else update(i, x, id * 2 + 1, m + 1, r);
 
		sg[id] = comb(sg[id * 2], sg[id * 2 + 1]); 
	}
 
	T query(int L, int R) { return query(L, R, 1, 1, n); }
 
	T query(int L, int R, int id, int l, int r) {
		if (L <= l && r <= R) return sg[id];
		if (R < l || L > r) return base; 
 
		int m = (l + r) / 2;
		return comb(query(L, R, id * 2, l, m), query(L, R, id * 2 + 1, m + 1, r)); 
	}
};
