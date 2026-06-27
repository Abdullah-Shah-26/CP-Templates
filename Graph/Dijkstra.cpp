vector<ll> dijkstra(int src, vector<vector<pair<int, int>>> &adj) {
  int n = adj.size();

  vector<ll> dist(n, LINF);
  priority_queue<pll, vector<pll>, greater<pll>> pq;

  dist[src] = 0;
  pq.push({0, src});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (d != dist[u])
      continue;

    for (auto [v, wt] : adj[u]) {
      if (dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
        pq.push({dist[v], v});
      }
    }
  }

  return dist;
}