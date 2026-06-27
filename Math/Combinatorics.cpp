class Combinatorics {
private:
  int n;

  ll modInverse(ll x) {
    return binExpo(x, MOD - 2);
  }

public:
  vector<ll> fact;
  vector<ll> invFact;

  Combinatorics(int n) {
    this->n = n;

    fact.assign(n + 1, 1);
    invFact.assign(n + 1, 1);

    for(int i = 1; i <= n; i++)
      fact[i] = fact[i - 1] * i % MOD;

    invFact[n] = modInverse(fact[n]);

    for(int i = n - 1; i >= 0; i--)
      invFact[i] = invFact[i + 1] * (i + 1) % MOD;
  }

  ll nCr(int n, int r) {
    if(r < 0 || r > n)
      return 0;

    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
  }

  ll nPr(int n, int r) {
    if(r < 0 || r > n)
      return 0;

    return fact[n] * invFact[n - r] % MOD;
  }
};