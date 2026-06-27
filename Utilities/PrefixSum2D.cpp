class PrefixSum2D {
private:
  vector<vector<ll>> pref;

public:
  PrefixSum2D(vector<vector<ll>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    pref.assign(n + 1, vector<ll>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        pref[i][j] = grid[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
      }
    }
  }

  ll query(int r1, int c1, int r2, int c2) {
    r1++;
    c1++;
    r2++;
    c2++;

    return pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1];
  }
};