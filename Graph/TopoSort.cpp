void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &topo) {
  vis[u] = true;

  for(int v : adj[u]) {
    if(!vis[v])
      dfs(v, adj, vis, topo);
  }

  topo.pb(u);
}

vector<int> topoSort(vector<vector<int>> &adj) {
  int n = adj.size();

  vector<bool> vis(n, false);
  vector<int> topo;

  for(int i = 0; i < n; i++) {
    if(!vis[i])
      dfs(i, adj, vis, topo);
  }

  reverse(all(topo));

  return topo;
}