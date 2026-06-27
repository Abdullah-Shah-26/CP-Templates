class BinaryTrie {
private:
  struct Node {
    Node *child[2];
    int cnt;

    Node() {
      child[0] = child[1] = nullptr;
      cnt = 0;
    }
  };

  Node *root;

public:
  BinaryTrie() {
    root = new Node();
  }

  void insert(int x) {
    Node *cur = root;

    for(int i = 31; i >= 0; i--) {
      int b = (x >> i) & 1;

      if(!cur->child[b])
        cur->child[b] = new Node();

      cur = cur->child[b];
      cur->cnt++;
    }
  }

  void erase(int x) {
    Node *cur = root;

    for(int i = 31; i >= 0; i--) {
      int b = (x >> i) & 1;

      cur = cur->child[b];
      cur->cnt--;
    }
  }

  int maxXor(int x) {
    Node *cur = root;
    int ans = 0;

    for(int i = 31; i >= 0; i--) {
      int b = (x >> i) & 1;

      if(cur->child[!b] && cur->child[!b]->cnt) {
        ans |= (1 << i);
        cur = cur->child[!b];
      }
      else {
        cur = cur->child[b];
      }
    }

    return ans;
  }

  int minXor(int x) {
    Node *cur = root;
    int ans = 0;

    for(int i = 31; i >= 0; i--) {
      int b = (x >> i) & 1;

      if(cur->child[b] && cur->child[b]->cnt) {
        cur = cur->child[b];
      }
      else {
        ans |= (1 << i);
        cur = cur->child[!b];
      }
    }

    return ans;
  }
};