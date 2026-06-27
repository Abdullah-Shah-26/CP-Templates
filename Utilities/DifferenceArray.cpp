class DiffArr {
private:
  vector<ll> diff;

public:
  DiffArr(int n) {
    diff.assign(n + 1, 0);
  }

  void update(int l, int r, ll val) {
    diff[l] += val;

    if(r + 1 < diff.size())
      diff[r + 1] -= val;
  }

  vector<ll> build() {
    int n = diff.size() - 1;

    vector<ll> a(n);

    a[0] = diff[0];

    for(int i = 1; i < n; i++)
      a[i] = a[i - 1] + diff[i];

    return a;
  }
};