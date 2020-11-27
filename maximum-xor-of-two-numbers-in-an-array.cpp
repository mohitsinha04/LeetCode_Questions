class TrieNode {
public:
    TrieNode* left; //for zeroes (0)
    TrieNode* right; //for ones (1)
};
​
void insert(TrieNode* root, int nums) {
    TrieNode* curr = root;
    for(int i = 31; i >= 0; i--) {
        //last bit of nums
        int b = (nums>>i) & 1;
        if(b) {
            //if b is 1 then we have to go for 1 side that is right side
            if(!curr->right) 
                curr->right = new TrieNode();
            curr = curr->right;
        } else { 
            //if b is 0 then we have to go for 0 side that is left side
            if(!curr->left)
                curr->left = new TrieNode();
            curr = curr->left;
        }
    }
}
​
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < nums.size(); i++) {
            //int val = nums[i];
            insert(root, nums[i]);
        }
        //maximum xor
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            int curr_max = 0; //local maximum xor for current element
            TrieNode* curr = root;
            for(int j = 31; j >= 0; j--) {
                //last bit of nums
                int b = (val >> j) & 1;
                //if last bit is 0 then we have to go right (one) for max xor!
                if(b == 0) { 
                    //for xor one!
                    if(curr->right){
                        //calculating maximum number of binary representation
                        curr_max += pow(2, j);
                        curr = curr->right;
                    } else //if there is no one, then we have to go for zero
                        curr = curr->left;
                }
                else {
                    //if last bit is 1 then we have to go left (one) for max xor!
                    if(curr->left) {
                        //calculating maximum number of binary representation
                        curr_max += pow(2, j);
                        curr = curr->left;
                    } else //if there is no zero, then we have to go for one
                        curr = curr->right;
                }
            }
            maxi = max(maxi, curr_max); //updating max xor!
        }
        return maxi;
    }
   
};
​
