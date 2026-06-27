vector<int> topoSort(vector<vector<int>> &adj) {
  int n = adj.size();

  vector<int> indegree(n, 0);

  for(int u = 0; u < n; u++) {
    for(int v : adj[u])
      indegree[v]++;
  }

  queue<int> q;

  for(int i = 0; i < n; i++) {
    if(indegree[i] == 0)
      q.push(i);
  }

  vector<int> topo;

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    topo.pb(u);

    for(int v : adj[u]) {
      indegree[v]--;

      if(indegree[v] == 0)
        q.push(v);
    }
  }

  return topo;
}