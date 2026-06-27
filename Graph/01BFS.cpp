vector<int> zeroOneBFS(int src, vector<vector<pair<int, int>>> &adj) {
  int n = adj.size();

  vector<int> dist(n, INF);
  deque<int> dq;

  dist[src] = 0;
  dq.push_front(src);

  while(!dq.empty()) {
    int u = dq.front();
    dq.pop_front();

    for(auto [v, wt] : adj[u]) {
      if(dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;

        if(wt == 0)
          dq.push_front(v);
        else
          dq.push_back(v);
      }
    }
  }

  return dist;
}