class SegTree {
private:
  int n;
  vector<ll> seg;

  void build(int i, int l, int r, vector<ll> &arr) {
    if (l == r) {
      seg[i] = arr[l];
      return;
    }

    int mid = l + ((r - l) >> 1);

    build(2 * i + 1, l, mid, arr);
    build(2 * i + 2, mid + 1, r, arr);

    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
  }

  void update(int i, int l, int r, int pos, ll val) {
    if (l == r) {
      seg[i] = val;
      return;
    }

    int mid = l + ((r - l) >> 1);

    if (pos <= mid)
      update(2 * i + 1, l, mid, pos, val);
    else
      update(2 * i + 2, mid + 1, r, pos, val);

    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
  }

  ll query(int i, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
      return 0;

    if (ql <= l && r <= qr)
      return seg[i];

    int mid = l + ((r - l) >> 1);

    return query(2 * i + 1, l, mid, ql, qr) +
           query(2 * i + 2, mid + 1, r, ql, qr);
  }

public:
  SegTree(vector<ll> &arr) {
    n = arr.size();
    seg.assign(4 * n, 0);

    build(0, 0, n - 1, arr);
  }

  void update(int pos, ll val) { update(0, 0, n - 1, pos, val); }

  ll query(int l, int r) { return query(0, 0, n - 1, l, r); }
};