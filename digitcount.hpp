using ll = long long;

ll L, R;
ll dp[11][11][2][2];

ll go(string n, int pos, int cnt, int small, int start) {
    if (pos == sz(n)) return cnt;
    ll &ret = dp[pos][cnt][small][start];
    if (ret != -1) return ret;
    ret = 0;

    int lim = (!small ? n[pos] - '0' : 9);
    if (start) {
        for (int d = 1; d <= lim; ++d) {
            ret += go(n, pos + 1, cnt, small | (d < n[pos] - '0'), 0);
        }
        ret += go(n, pos + 1, 0, 1, 1);
    }
    else {
        for (int d = 0; d <= lim; ++d) {
            ret += go(n, pos + 1, cnt + (d == 0), small | (d < n[pos] - '0'), 0);
        }
    }

    return ret;
}

ll calc(ll x) {
    if (x < 0) return 0;
    string n = to_string(x);
    memset(dp, -1, sizeof dp);
    return go(n, 0, 0, 0, 1) + 1;
}
