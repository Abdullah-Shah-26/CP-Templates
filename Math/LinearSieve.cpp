class LinearSieve {
public:
  vector<int> primes;
  vector<int> spf;

  LinearSieve(int n) {
    spf.assign(n + 1, 0);

    for(int i = 2; i <= n; i++) {
      if(spf[i] == 0) {
        spf[i] = i;
        primes.pb(i);
      }

      for(int p : primes) {
        if(p > spf[i] || 1LL * i * p > n)
          break;

        spf[i * p] = p;
      }
    }
  }

  vector<int> primeFactors(int x) {
    vector<int> factors;

    while(x > 1) {
      factors.pb(spf[x]);
      x /= spf[x];
    }

    return factors;
  }

  vector<pii> primeFactorFreq(int x) {
    vector<pii> factors;

    while(x > 1) {
      int prime = spf[x];
      int cnt = 0;

      while(x > 1 && spf[x] == prime) {
        cnt++;
        x /= prime;
      }

      factors.pb({prime, cnt});
    }

    return factors;
  }
};