class ArticulationPoint {
private:
  int timer;
  vector<int> tin, low;
  vector<bool> vis;

  vector<vector<int>> &adj;

  void dfs(int u, int p) {
    vis[u] = true;
    tin[u] = low[u] = timer++;

    int child = 0;

    for(int v : adj[u]) {
      if(v == p)
        continue;

      if(vis[v]) {
        low[u] = min(low[u], tin[v]);
      }
      else {
        dfs(v, u);

        low[u] = min(low[u], low[v]);

        if(p != -1 && low[v] >= tin[u])
          articulation.pb(u);

        child++;
      }
    }

    if(p == -1 && child > 1)
      articulation.pb(u);
  }

public:
  vector<int> articulation;

  ArticulationPoint(vector<vector<int>> &adj)
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

    sort(all(articulation));
    articulation.erase(unique(all(articulation)), articulation.end());
  }
};