template<typename T, class F = function<T(const T&, const T&)>> struct sparse_table {      
    int n;
    vector<vector<T>> spa;
    F func;

    sparse_table(const vector<T>& a, const F& f) : func(f) {
        n = (int)a.size();
        int max_log = 32 - __builtin_clz(n);
        spa.resize(max_log);
        spa[0] = a;
        for (int j = 1; j < max_log; j++) {
            spa[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                spa[j][i] = func(spa[j - 1][i], spa[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 31 - __builtin_clz(to - from + 1);
        return func(spa[lg][from], spa[lg][to - (1 << lg) + 1]);
    }
};
