class Node {
public:
  ll sum;

  Node(ll val = 0) {
    sum = val;
  }
};

class NodeSeg {
private:
  int n;
  vector<Node> seg;

  Node merge(Node left, Node right) {
    Node res;

    res.sum = left.sum + right.sum;

    return res;
  }

  void build(int i, int l, int r, vector<ll> &arr) {
    if(l == r) {
      seg[i] = Node(arr[l]);
      return;
    }

    int mid = l + ((r - l) >> 1);

    build(2 * i + 1, l, mid, arr);
    build(2 * i + 2, mid + 1, r, arr);

    seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
  }

  void update(int i, int l, int r, int pos, ll val) {
    if(l == r) {
      seg[i] = Node(val);
      return;
    }

    int mid = l + ((r - l) >> 1);

    if(pos <= mid)
      update(2 * i + 1, l, mid, pos, val);
    else
      update(2 * i + 2, mid + 1, r, pos, val);

    seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
  }

  Node query(int i, int l, int r, int ql, int qr) {
    if(qr < l || r < ql)
      return Node();

    if(ql <= l && r <= qr)
      return seg[i];

    int mid = l + ((r - l) >> 1);

    return merge(
      query(2 * i + 1, l, mid, ql, qr),
      query(2 * i + 2, mid + 1, r, ql, qr)
    );
  }

public:
  NodeSeg(vector<ll> &arr) {
    n = arr.size();
    seg.assign(4 * n, Node());

    build(0, 0, n - 1, arr);
  }

  // Point Update: Set arr[pos] = val.
  void update(int pos, ll val) {
    update(0, 0, n - 1, pos, val);
  }

  // Range Query.
  Node query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }
};