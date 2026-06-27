ll kruskal(int n, vector<tuple<int, int, int>> &edges) {
  sort(all(edges));

  DSU dsu(n);

  ll mst = 0;

  for(auto [wt, u, v] : edges) {
    if(dsu.unite(u, v))
      mst += wt;
  }

  return mst;
}