class MonoStack {
public:
  vector<int> NGE(vector<ll> &a) {
    int n = a.size();

    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {
      while(!st.empty() && a[st.top()] <= a[i])
        st.pop();

      if(!st.empty())
        ans[i] = st.top();

      st.push(i);
    }

    return ans;
  }

  vector<int> NSE(vector<ll> &a) {
    int n = a.size();

    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {
      while(!st.empty() && a[st.top()] >= a[i])
        st.pop();

      if(!st.empty())
        ans[i] = st.top();

      st.push(i);
    }

    return ans;
  }

  vector<int> PGE(vector<ll> &a) {
    int n = a.size();

    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++) {
      while(!st.empty() && a[st.top()] <= a[i])
        st.pop();

      if(!st.empty())
        ans[i] = st.top();

      st.push(i);
    }

    return ans;
  }

  vector<int> PSE(vector<ll> &a) {
    int n = a.size();

    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++) {
      while(!st.empty() && a[st.top()] >= a[i])
        st.pop();

      if(!st.empty())
        ans[i] = st.top();

      st.push(i);
    }

    return ans;
  }
};