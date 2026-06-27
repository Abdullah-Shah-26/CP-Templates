void dfs(int u, int p, vector<vector<int>> &adj) {
  for(int v : adj[u]) {
    if(v == p)
      continue;

    dfs(v, u, adj);
  }
}