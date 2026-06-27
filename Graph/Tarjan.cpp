class Tarjan {
private:
  int timer;
  vector<int> tin, low;
  vector<bool> inStack;
  stack<int> st;

  vector<vector<int>> &adj;

  void dfs(int u) {
    tin[u] = low[u] = timer++;

    st.push(u);
    inStack[u] = true;

    for(int v : adj[u]) {
      if(tin[v] == -1) {
        dfs(v);
        low[u] = min(low[u], low[v]);
      }
      else if(inStack[v]) {
        low[u] = min(low[u], tin[v]);
      }
    }

    if(tin[u] == low[u]) {
      vector<int> comp;

      while(true) {
        int v = st.top();
        st.pop();

        inStack[v] = false;
        comp.push_back(v);

        if(v == u)
          break;
      }

      sccs.push_back(comp);
    }
  }

public:
  vector<vector<int>> sccs;

  Tarjan(vector<vector<int>> &adj)
      : adj(adj) {

    int n = adj.size();

    timer = 0;

    tin.assign(n, -1);
    low.assign(n, -1);
    inStack.assign(n, false);

    for(int i = 0; i < n; i++) {
      if(tin[i] == -1)
        dfs(i);
    }
  }
};