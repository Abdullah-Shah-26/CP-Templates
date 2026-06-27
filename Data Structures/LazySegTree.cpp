class LazySeg {
private:
  int n;
  vector<ll> seg, lazy;

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

  void push(int i, int l, int r) {
    if (lazy[i] == 0)
      return;

    seg[i] += (r - l + 1) * lazy[i];

    if (l != r) {
      lazy[2 * i + 1] += lazy[i];
      lazy[2 * i + 2] += lazy[i];
    }

    lazy[i] = 0;
  }

  // Range Update: Add val to every element in [ql, qr]
  void update(int i, int l, int r, int ql, int qr, ll val) {
    push(i, l, r);

    if (r < ql || qr < l)
      return;

    if (ql <= l && r <= qr) {
      lazy[i] += val;
      push(i, l, r);
      return;
    }

    int mid = l + ((r - l) >> 1);

    update(2 * i + 1, l, mid, ql, qr, val);
    update(2 * i + 2, mid + 1, r, ql, qr, val);

    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
  }

  ll query(int i, int l, int r, int ql, int qr) {
    push(i, l, r);

    if (r < ql || qr < l)
      return 0;

    if (ql <= l && r <= qr)
      return seg[i];

    int mid = l + ((r - l) >> 1);

    return query(2 * i + 1, l, mid, ql, qr) +
           query(2 * i + 2, mid + 1, r, ql, qr);
  }

public:
  LazySeg(vector<ll> &arr) {
    n = arr.size();

    seg.assign(4 * n, 0);
    lazy.assign(4 * n, 0);

    build(0, 0, n - 1, arr);
  }

  void update(int l, int r, ll val) { update(0, 0, n - 1, l, r, val); }

  ll query(int l, int r) { return query(0, 0, n - 1, l, r); }
};