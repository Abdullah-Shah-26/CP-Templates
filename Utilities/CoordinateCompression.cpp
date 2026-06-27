class CoordinateCompression {
private:
  vector<ll> vals;

public:
  void compress(vector<ll> &a) {
    vals = a;

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    for(ll &x : a)
      x = lower_bound(all(vals), x) - vals.begin();
  }

  int get(ll x) {
    return lower_bound(all(vals), x) - vals.begin();
  }

  ll original(int idx) {
    return vals[idx];
  }
};
