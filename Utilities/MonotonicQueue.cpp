class MonoQueue {
public:
  vector<ll> maxWindow(vector<ll> &a, int k) {
    deque<int> dq;
    vector<ll> ans;

    for (int i = 0; i < a.size(); i++) {
      while (!dq.empty() && dq.front() <= i - k)
        dq.pop_front();

      while (!dq.empty() && a[dq.back()] <= a[i])
        dq.pop_back();

      dq.push_back(i);

      if (i >= k - 1)
        ans.pb(a[dq.front()]);
    }

    return ans;
  }

  vector<ll> minWindow(vector<ll> &a, int k) {
    deque<int> dq;
    vector<ll> ans;

    for (int i = 0; i < a.size(); i++) {
      while (!dq.empty() && dq.front() <= i - k)
        dq.pop_front();

      while (!dq.empty() && a[dq.back()] >= a[i])
        dq.pop_back();

      dq.push_back(i);

      if (i >= k - 1)
        ans.pb(a[dq.front()]);
    }

    return ans;
  }
};