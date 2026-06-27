vector<vector<ll>> floydWarshall(vector<vector<ll>> dist) {
  int n = dist.size();

  for (int via = 0; via < n; via++) {
    for (int i = 0; i < n; i++) {
      if (dist[i][via] == LINF)
        continue;

      for (int j = 0; j < n; j++) {
        if (dist[via][j] == LINF)
          continue;

        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
      }
    }
  }

  return dist;
}