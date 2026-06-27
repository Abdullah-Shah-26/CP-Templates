class Kosaraju {
private:
  int n;
  vector<vector<int>> adj, rev;
  vector<bool> vis;
  vector<int> order;

  void dfs1(int u) {
    vis[u] = true;

    for(int v : adj[u]) {
      if(!vis[v])
        dfs1(v);
    }

    order.push_back(u);
  }

  void dfs2(int u, vector<int> &comp) {
    vis[u] = true;
    comp.push_back(u);

    for(int v : rev[u]) {
      if(!vis[v])
        dfs2(v, comp);
    }
  }

public:
  Kosaraju(vector<vector<int>> &adj) {
    this->adj = adj;

    n = adj.size();

    rev.assign(n, {});

    for(int u = 0; u < n; u++) {
      for(int v : adj[u])
        rev[v].push_back(u);
    }
  }

  vector<vector<int>> scc() {
    vis.assign(n, false);
    order.clear();

    for(int i = 0; i < n; i++) {
      if(!vis[i])
        dfs1(i);
    }

    reverse(all(order));

    vis.assign(n, false);

    vector<vector<int>> sccs;

    for(int u : order) {
      if(vis[u])
        continue;

      vector<int> comp;
      dfs2(u, comp);

      sccs.push_back(comp);
    }

    return sccs;
  }
};