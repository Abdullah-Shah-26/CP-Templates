void bfs(int src, vector<vector<int>> &adj) {
  int n = adj.size();

  vector<bool> vis(n, false);
  queue<int> q;

  vis[src] = true;
  q.push(src);

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    for(int v : adj[u]) {
      if(vis[v])
        continue;

      vis[v] = true;
      q.push(v);
    }
  }
}