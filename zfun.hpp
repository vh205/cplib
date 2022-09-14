vector<int> Zfun(string S) {
    int N = (int)S.size();
    vector<int> Z(N);
    for (int i = 1, l = 0, r = 0; i < N; ++i) {
        if (i <= r) Z[i] = min(Z[i - l], r - i + 1);
        while (i + Z[i] < N && S[Z[i]] == S[Z[i] + i]) ++Z[i];
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}
