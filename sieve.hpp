const int maxA = 1e7;
vector<int> pr;
int lp[maxA + 5];

void sieve() {
    for (int i = 2; i <= maxA; ++i) {
        if (!lp[i]) {
            lp[i] = i;
            pr.emplace_back(i);
        }
        for (auto &j : pr) {
            if (i * j > maxA || j > lp[i]) break;
            lp[i * j] = j;
        }
    }
}
