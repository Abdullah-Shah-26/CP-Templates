class DSU {
private:
  vector<int> parent;
  vector<int> size;

public:
  // Creates n disjoint sets: {0}, {1}, ..., {n-1}
  DSU(int n) {
    parent.resize(n);
    size.assign(n, 1);

    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  // Finds the representative (leader) of the set
  int find(int node) {
    if (parent[node] == node)
      return node;

    return parent[node] = find(parent[node]); // Path Compression
  }

  // Returns true if union happened
  // Returns false if both nodes were already in the same component
  bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
      return false;

    // Union by Size
    if (size[u] < size[v])
      swap(u, v);

    parent[v] = u;
    size[u] += size[v];

    return true;
  }

  bool same(int u, int v) { return find(u) == find(v); }

  int compSz(int node) { return size[find(node)]; }

  int leader(int node) { return find(node); }
};