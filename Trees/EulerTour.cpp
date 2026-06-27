class EulerTour {
private:
  vector<vector<int>> &adj;
  int timer;

  void dfs(int u, int p) {
    tin[u] = timer++;
    euler.push_back(u);

    for (int v : adj[u]) {
      if (v == p)
        continue;

      dfs(v, u);
    }

    tout[u] = timer - 1;
  }

public:
  vector<int> tin;
  vector<int> tout;
  vector<int> euler;

  EulerTour(vector<vector<int>> &adj, int root = 0) : adj(adj) {
    int n = adj.size();

    tin.resize(n);
    tout.resize(n);
    euler.reserve(n);
    timer = 0;

    dfs(root, -1);
  }

  bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
  }
};