template <int MOD>
class mod_int {
    using mint = mod_int<MOD>;
 
private:
    template <typename T>
    int64_t mod(const T& x) const {
        return (x % MOD + MOD) % MOD;
    }
    int64_t powmod(const int64_t & a, const int64_t & n) const {
        if (n == 0) return 1;
        int64_t res = powmod(a, n / 2);
        res = res * res % MOD;
        if (n % 2 == 1) res = res * a % MOD;
        return res;
    }
 
public:
    int64_t val;
    mod_int(): val(0) {}
    template <typename T> mod_int(const T& x) { val = mod(x); }
    mint pow(const int64_t& N) const { return mint(powmod(val, N)); }
    mint inv() const { return powmod(val, MOD - 2); }
    void operator ++ () { val = mod(val + 1); }
    void operator ++ (int) { val = mod(val + 1); }
    void operator -- () { val = mod(val - 1); }
    void operator -- (int) { val = mod(val - 1); }
    void operator += (const mint& x) { val = mod(val + x.val); }
    void operator -= (const mint& x) { val = mod(val - x.val); }
    void operator *= (const mint& x) { val = mod(val * x.val); }
    void operator /= (const mint& x) { val = mod(val * x.inv()); }
    mint operator + () const { return (*this); }
    mint operator - () const { return mint(0) - (*this); }
    friend mint operator + (const mint& x, const mint& y) { return mint(x.val + y.val); }
    friend mint operator - (const mint& x, const mint& y) { return mint(x.val - y.val); }
    friend mint operator * (const mint& x, const mint& y) { return mint(x.val * y.val); }
    friend mint operator / (const mint& x, const mint& y) { return mint(x.val * y.inv()); }
    friend bool operator == (const mint& x, const mint& y) { return x.val == y.val; }
    friend bool operator != (const mint& x, const mint& y) { return x.val != y.val; }
    friend ostream& operator << (ostream& out, const mint& n) { return out << (int)n.val; }
    friend istream& operator >> (istream& in, mint& n) { int64_t x; in >> x; n = mint(x); return in; }
};
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
using mint = mod_int<MOD>;
