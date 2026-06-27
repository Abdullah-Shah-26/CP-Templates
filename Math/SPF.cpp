class SPF {
public:
  vector<int> spf;

  SPF(int n) {
    spf.resize(n + 1);

    for(int i = 0; i <= n; i++)
      spf[i] = i;

    for(int i = 2; i * i <= n; i++) {
      if(spf[i] != i)
        continue;

      for(int j = i * i; j <= n; j += i) {
        if(spf[j] == j)
          spf[j] = i;
      }
    }
  }

  vector<int> primeFactors(int x) {
    vector<int> factors;

    while(x > 1) {
      factors.push_back(spf[x]);
      x /= spf[x];
    }

    return factors;
  }

  vector<pair<int, int>> primeFactorFreq(int x) {
    vector<pair<int, int>> factors;

    while(x > 1) {
      int prime = spf[x];
      int cnt = 0;

      while(x > 1 && spf[x] == prime) {
        cnt++;
        x /= prime;
      }

      factors.push_back({prime, cnt});
    }

    return factors;
  }
};