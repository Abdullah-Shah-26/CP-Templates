class RollingHash {
private:
  static const ll MOD1 = 1000000007;
  static const ll MOD2 = 1000000009;

  static const ll BASE1 = 911382323 % MOD1;
  static const ll BASE2 = 972663749 % MOD2;
  string s;

  vector<ll> hash1, hash2;
  vector<ll> pow1, pow2;

public:
  RollingHash(string &s) {
    this->s = s;

    int n = s.size();

    hash1.assign(n + 1, 0);
    hash2.assign(n + 1, 0);

    pow1.assign(n + 1, 1);
    pow2.assign(n + 1, 1);

    for (int i = 1; i <= n; i++) {
      pow1[i] = pow1[i - 1] * BASE1 % MOD1;
      pow2[i] = pow2[i - 1] * BASE2 % MOD2;

      hash1[i] = (hash1[i - 1] * BASE1 + s[i - 1]) % MOD1;
      hash2[i] = (hash2[i - 1] * BASE2 + s[i - 1]) % MOD2;
    }
  }

  // Returns hash of s[l...r]
  pll getHash(int l, int r) {
    ll x1 = (hash1[r + 1] - hash1[l] * pow1[r - l + 1]) % MOD1;
    if (x1 < 0)
      x1 += MOD1;

    ll x2 = (hash2[r + 1] - hash2[l] * pow2[r - l + 1]) % MOD2;
    if (x2 < 0)
      x2 += MOD2;

    return {x1, x2};
  }
};