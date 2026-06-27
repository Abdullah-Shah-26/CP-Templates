class LCA {
private:
  int n, LOG;
  vector<vector<int>> adj;
  vector<vector<int>> up;
  vector<int> depth;

  void dfs(int u, int p) {
    up[u][0] = p;

    for (int j = 1; j < LOG; j++) {
      if (up[u][j - 1] == -1)
        up[u][j] = -1;
      else
        up[u][j] = up[up[u][j - 1]][j - 1];
    }

    for (int v : adj[u]) {
      if (v == p)
        continue;

      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
  }

public:
  LCA(vector<vector<int>> &adj, int root = 0) {
    this->adj = adj;

    n = adj.size();
    LOG = __lg(n) + 1;

    up.assign(n, vector<int>(LOG, -1));
    depth.assign(n, 0);

    dfs(root, -1);
  }

  int kthAncestor(int u, int k) {
    for (int j = 0; j < LOG && u != -1; j++) {
      if (k & (1 << j))
        u = up[u][j];
    }

    return u;
  }

  int lca(int u, int v) {
    if (depth[u] < depth[v])
      swap(u, v);

    u = kthAncestor(u, depth[u] - depth[v]);

    if (u == v)
      return u;

    for (int j = LOG - 1; j >= 0; j--) {
      if (up[u][j] != up[v][j]) {
        u = up[u][j];
        v = up[v][j];
      }
    }

    return up[u][0];
  }

  int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }

  int getDepth(int u) { return depth[u]; }
};