class MatrixExpo {
private:
  vector<vector<ll>> multiply(vector<vector<ll>> &a, vector<vector<ll>> &b) {
    int n = a.size();

    vector<vector<ll>> c(n, vector<ll>(n, 0));

    for(int i = 0; i < n; i++) {
      for(int k = 0; k < n; k++) {
        for(int j = 0; j < n; j++) {
          c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
        }
      }
    }

    return c;
  }

public:
  vector<vector<ll>> power(vector<vector<ll>> mat, ll exp) {
    int n = mat.size();

    vector<vector<ll>> res(n, vector<ll>(n, 0));

    for(int i = 0; i < n; i++)
      res[i][i] = 1;

    while(exp > 0) {
      if(exp & 1)
        res = multiply(res, mat);

      mat = multiply(mat, mat);

      exp >>= 1;
    }

    return res;
  }
};