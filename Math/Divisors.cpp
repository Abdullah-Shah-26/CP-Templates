class Divisors {
public:
  vector<vector<int>> divisors;

  Divisors(int n) {
    divisors.resize(n + 1);

    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i)
        divisors[j].push_back(i);
    }
  }
};