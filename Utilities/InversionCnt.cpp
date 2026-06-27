class InversionCount {
private:
  ll merge(vector<ll> &a, int l, int mid, int r) {
    vector<ll> temp;

    int i = l;
    int j = mid + 1;

    ll inv = 0;

    while(i <= mid && j <= r) {
      if(a[i] <= a[j]) {
        temp.pb(a[i++]);
      }
      else {
        inv += mid - i + 1;
        temp.pb(a[j++]);
      }
    }

    while(i <= mid)
      temp.pb(a[i++]);

    while(j <= r)
      temp.pb(a[j++]);

    for(int k = l; k <= r; k++)
      a[k] = temp[k - l];

    return inv;
  }

  ll mergeSort(vector<ll> &a, int l, int r) {
    if(l >= r)
      return 0;

    int mid = l + ((r - l) >> 1);

    ll inv = 0;

    inv += mergeSort(a, l, mid);
    inv += mergeSort(a, mid + 1, r);
    inv += merge(a, l, mid, r);

    return inv;
  }

public:
  ll count(vector<ll> a) {
    return mergeSort(a, 0, a.size() - 1);
  }
};