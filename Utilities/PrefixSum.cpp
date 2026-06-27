class PrefixSum {
private:
  vector<ll> pref;

public:
  PrefixSum(vector<ll> &a) {
    int n = a.size();

    pref.assign(n + 1, 0);

    for(int i = 0; i < n; i++)
      pref[i + 1] = pref[i] + a[i];
  }

  ll query(int l, int r) {
    return pref[r + 1] - pref[l];
  }
};