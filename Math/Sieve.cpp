class Sieve {
public:
  vector<bool> isPrime;
  vector<int> primes;

  Sieve(int n) {
    isPrime.assign(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= n; i++) {
      if(!isPrime[i])
        continue;

      for(int j = i * i; j <= n; j += i)
        isPrime[j] = false;
    }

    for(int i = 2; i <= n; i++) {
      if(isPrime[i])
        primes.push_back(i);
    }
  }
};