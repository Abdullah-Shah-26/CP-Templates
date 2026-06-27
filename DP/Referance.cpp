class DPReference {
public:
  // Knapsack
  void Knapsack() {
    /*
    vector<vector<ll>> dp(
        n + 1,
        vector<ll>(W + 1));

    for(int i = 1; i <= n; i++) {
      for(int w = 0; w <= W; w++) {
        // Take
        // Not Take
      }
    }
    */
  }

  // Bitmask DP
  void BitmaskDP() {
    /*
    vector<vector<ll>> dp(
        1 << n,
        vector<ll>(n, -1));

    // dp[mask][last]
    */
  }

  // Digit DP
  void DigitDP() {
    /*
    ll dp[20][2][2];

    ll f(int pos, bool tight, bool started) {
    }
    */
  }

  // Tree DP
  void TreeDP() {
    /*
    void dfs(int u, int p) {
      for(int v : adj[u]) {
        if(v == p)
          continue;

        dfs(v, u);

        // Merge
      }
    }
    */
  }

  // Interval DP
  void IntervalDP() {
    /*
    vector<vector<ll>> dp(
        n,
        vector<ll>(n));

    for(int len = 1; len <= n; len++) {
      for(int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;

        // Transition
      }
    }
    */
  }

  // SOS DP
  void SOSDP() {
    /*
    vector<ll> dp(1 << n);

    for(int bit = 0; bit < n; bit++) {
      for(int mask = 0; mask < (1 << n); mask++) {
        if(mask & (1 << bit))
          dp[mask] += dp[mask ^ (1 << bit)];
      }
    }
    */
  }
};