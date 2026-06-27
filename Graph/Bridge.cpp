class Bridge {
private:
  int timer;
  vector<int> tin, low;
  vector<bool> vis;

  vector<vector<int>> &adj;

  void dfs(int u, int p) {
    vis[u] = true;
    tin[u] = low[u] = timer++;

    for(int v : adj[u]) {
      if(v == p)
        continue;

      if(vis[v]) {
        low[u] = min(low[u], tin[v]);
      }
      else {
        dfs(v, u);

        low[u] = min(low[u], low[v]);

        if(low[v] > tin[u])
          bridges.pb({u, v});
      }
    }
  }

public:
  vector<pii> bridges;

  Bridge(vector<vector<int>> &adj)
      : adj(adj) {

    int n = adj.size();

    timer = 0;

    tin.assign(n, -1);
    low.assign(n, -1);
    vis.assign(n, false);

    for(int i = 0; i < n; i++) {
      if(!vis[i])
        dfs(i, -1);
    }
  }
};