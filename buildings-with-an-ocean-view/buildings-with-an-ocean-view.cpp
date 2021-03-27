class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
  int max_til_now = heights[heights.size() - 1];
  res.push_back(heights.size() - 1);
  for(int i = heights.size() - 2; i >= 0; i--) {
    if(heights[i] > max_til_now) {
      res.push_back(i);
    }
    max_til_now = max(heights[i], max_til_now);
  }
        reverse(res.begin(), res.end());
  return res;
    }
};