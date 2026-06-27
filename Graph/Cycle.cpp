// UnDirected Graph Cycle Detection 

bool dfs(int u, int p, vector<vector<int>> &adj, vector<bool> &vis) {
  vis[u] = true;

  for(int v : adj[u]) {
    if(!vis[v]) {
      if(dfs(v, u, adj, vis))
        return true;
    }
    else if(v != p) {
      return true;
    }
  }

  return false;
}

bool hasCycle(vector<vector<int>> &adj) {
  int n = adj.size();

  vector<bool> vis(n, false);

  for(int i = 0; i < n; i++) {
    if(!vis[i] && dfs(i, -1, adj, vis))
      return true;
  }

  return false;
}