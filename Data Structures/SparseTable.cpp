class SparseTable {
private:
  vector<vector<ll>> st;
  vector<int> lg;

public:
  SparseTable(vector<ll> &a) {
    int n = a.size();

    lg.assign(n + 1, 0);

    for (int i = 2; i <= n; i++)
      lg[i] = lg[i / 2] + 1;

    int k = lg[n] + 1;

    st.assign(k, vector<ll>(n));

    st[0] = a;

    for (int j = 1; j < k; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  ll query(int l, int r) {
    int j = lg[r - l + 1];

    return min(st[j][l], st[j][r - (1 << j) + 1]);
  }
};
