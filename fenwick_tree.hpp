template<class T> struct fenwick_tree {
    vector<T> bit;
    int n;
 
    fenwick_tree(int _n) {
        init(_n);
    }
 
    void init(int _n) {
	n = _n;
        bit.assign(n, 0);
    }
 
    fenwick_tree(vector<int> a) : fenwick_tree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
 
    T sum(int p) {
        T res = 0;
        for (; p >= 0; p = (p & (p + 1)) - 1)
            res += bit[p];
        return res;
    }
 
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
 
    void add(int p, T x) {
        for (; p < n; p = p | (p + 1))
            bit[p] += x;
    }
};
