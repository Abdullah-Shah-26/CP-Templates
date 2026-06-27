bool dfs(int u, vector<vector<int>> &adj, vector<int> &vis) {
  vis[u] = 1;

  for(int v : adj[u]) {
    if(vis[v] == 0) {
      if(dfs(v, adj, vis))
        return true;
    }
    else if(vis[v] == 1) {
      return true;
    }
  }

  vis[u] = 2;

  return false;
}

bool hasCycle(vector<vector<int>> &adj) {
  int n = adj.size();

  vector<int> vis(n, 0);

  for(int i = 0; i < n; i++) {
    if(vis[i] == 0 && dfs(i, adj, vis))
      return true;
  }

  return false;
}