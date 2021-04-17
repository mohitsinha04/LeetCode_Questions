class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long sum = 0, all_neg = true, all_pos = true;
        long modulo = 1000000007;
  for(int i : arr) {
    sum += i;
    if(i > 0) all_neg = false; 
    if(i < 0) all_pos = false;
  }
  if(all_neg) return 0;
    if(all_pos) return (int)(sum*k % modulo);
  int running_sum = 0, max_sum = 0;
  bool is_two_visited = false;
  int i = 0;
  while(i < arr.size()) {
    running_sum += arr[i];
    max_sum = max(running_sum, max_sum);
    if(running_sum < 0) running_sum = 0;
    
    if(i == arr.size() - 1 && k >= 2 && is_two_visited == false) {
      i = -1;
      is_two_visited = true;
    }
    
    i++;
  }
  
  if(sum <= 0 || k <= 2) return (int)max_sum % modulo;
        long maxi = max_sum + sum*(k-2);
  return (int)(maxi % modulo);
    }
};