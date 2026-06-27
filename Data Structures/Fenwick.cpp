class Fenwick {
private:
  int n;
  vector<ll> bit;

public:
  Fenwick(int n) {
    this->n = n;
    bit.assign(n + 1, 0);
  }

  void update(int idx, ll val) {
    idx++;

    while(idx <= n) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }

  ll query(int idx) {
    idx++;

    ll sum = 0;

    while(idx > 0) {
      sum += bit[idx];
      idx -= idx & -idx;
    }

    return sum;
  }

  ll rangeQuery(int left, int right) {
    if(left > right)
      return 0;

    return query(right) - (left ? query(left - 1) : 0);
  }
};