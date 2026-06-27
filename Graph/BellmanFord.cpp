pair<vector<ll>, bool> bellmanFord(int src, int n, vector<tuple<int, int, int>> &edges) {
  vector<ll> dist(n, LINF);

  dist[src] = 0;

  for(int i = 1; i < n; i++) {
    bool changed = false;

    for(auto [u, v, wt] : edges) {
      if(dist[u] == LINF)
        continue;

      if(dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
        changed = true;
      }
    }

    if(!changed)
      break;
  }

  bool negCycle = false;

  for(auto [u, v, wt] : edges) {
    if(dist[u] == LINF)
      continue;

    if(dist[v] > dist[u] + wt) {
      negCycle = true;
      break;
    }
  }

  return {dist, negCycle};
}