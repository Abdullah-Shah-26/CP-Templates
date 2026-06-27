pair<ll, bool> prim(int src, vector<vector<pair<int, int>>> &adj) {
  int n = adj.size();

  vector<bool> vis(n, false);
  priority_queue<pll, vector<pll>, greater<pll>> pq;

  pq.push({0, src});

  ll mst = 0;
  int cnt = 0;

  while(!pq.empty()) {
    auto [wt, u] = pq.top();
    pq.pop();

    if(vis[u])
      continue;

    vis[u] = true;
    mst += wt;
    cnt++;

    for(auto [v, wt] : adj[u]) {
      if(!vis[v])
        pq.push({wt, v});
    }
  }

  return {mst, cnt == n};
}