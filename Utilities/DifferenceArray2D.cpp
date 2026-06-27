class DiffArr2D {
private:
  vector<vector<ll>> diff;

public:
  DiffArr2D(int n, int m) {
    diff.assign(n + 1, vector<ll>(m + 1, 0));
  }

  void update(int r1, int c1, int r2, int c2, ll val) {
    diff[r1][c1] += val;

    if(r2 + 1 < diff.size())
      diff[r2 + 1][c1] -= val;

    if(c2 + 1 < diff[0].size())
      diff[r1][c2 + 1] -= val;

    if(r2 + 1 < diff.size() && c2 + 1 < diff[0].size())
      diff[r2 + 1][c2 + 1] += val;
  }

  vector<vector<ll>> build() {
    int n = diff.size() - 1;
    int m = diff[0].size() - 1;

    vector<vector<ll>> a(n, vector<ll>(m));

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        a[i][j] = diff[i][j];

        if(i)
          a[i][j] += a[i - 1][j];

        if(j)
          a[i][j] += a[i][j - 1];

        if(i && j)
          a[i][j] -= a[i - 1][j - 1];
      }
    }

    return a;
  }
};