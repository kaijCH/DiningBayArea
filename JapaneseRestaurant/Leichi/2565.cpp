#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumScore(string s, string t) {
    int n = s.size(), m = t.size(), k = t.size() - 1;
    vector<int> dp(m, -1);
    for (int i = n - 1; i >= 0 && k >= 0; --i) {
      if (s[i] == t[k]) {
        dp[k--] = i;
      }
    }
    int ans = k + 1;
    for (int i = 0, j = 0; i < n && j < m && ans > 0; ++i) {
      if (s[i] == t[j]) {
        for (; k < m && dp[k] <= i; ++k) {
        }
        ans = min(ans, k - (++j));
      }
    }
    return ans;
  }
};