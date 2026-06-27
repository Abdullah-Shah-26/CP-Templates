class LIS {
public:
  int length(vector<ll> &a) {
    vector<ll> lis;

    for(ll x : a) {
      auto it = lower_bound(all(lis), x);

      if(it == lis.end())
        lis.pb(x);
      else
        *it = x;
    }

    return lis.size();
  }
};
