#include <bits/stdc++.h>
using namespace std;
class Solution {
  int func(vector<int>& weights, int x) {
    int ans = 0, temp = 0;
    for (int w : weights) {
      temp += w;
      if (temp > x) {
        ++ans;
        temp = w;
      }
    }
    return ans + 1;
  }

 public:
  int shipWithinDays(vector<int>& weights, int days) {
    int l = 0, r = 0;
    for (int weight : weights) {
      if (weight > l) l = weight;
      r += weight;
    }
    while (l < r) {
      int mid = (l + r) / 2;
      if (func(weights, mid) <= days)
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
};