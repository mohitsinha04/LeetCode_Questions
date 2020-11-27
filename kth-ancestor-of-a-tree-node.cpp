class TreeAncestor {
public:
    //https://www.youtube.com/watch?v=ctZ7fjMbPWE
    vector<vector<int>> memo;
    TreeAncestor(int n, vector<int>& parent) {
        memo.resize(n, vector<int>(20, -1));
        //2 ^ 0 level
        for(int i = 0; i < n; i++) memo[i][0] = parent[i];
        // rest level
        for(int j = 1; j < 20; j++) {
            for(int i = 0; i < n; i++) {
                if(memo[i][j-1] == -1) memo[i][j] = -1; //if it has no parent!
                else memo[i][j] = memo[memo[i][j-1]][j-1]; // h/2 = 2^i-1
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        //for 20 levels
        for (int i = 0; i < 20; i++) {
            //kth ancestor
            int boom = (k >> i);
            if (boom & 1) {
                node = memo[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};
​
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
