class KMP {
public:
  vector<int> lps;

  KMP(string &pat) {
    int n = pat.size();

    lps.assign(n, 0);

    for(int i = 1, j = 0; i < n; i++) {
      while(j > 0 && pat[i] != pat[j])
        j = lps[j - 1];

      if(pat[i] == pat[j])
        j++;

      lps[i] = j;
    }
  }

  vector<int> search(string &text, string &pat) {
    vector<int> occ;

    for(int i = 0, j = 0; i < text.size(); i++) {
      while(j > 0 && text[i] != pat[j])
        j = lps[j - 1];

      if(text[i] == pat[j])
        j++;

      if(j == pat.size()) {
        occ.push_back(i - j + 1);
        j = lps[j - 1];
      }
    }

    return occ;
  }
};