struct Node{
    Node* links[2];

    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    void put(Node* node , int bit){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(int num){
            Node* node = root;
            for(int i = 31; i>=0; i--){
                int bit = (num>>i) & 1;
                if(!node->containsKey(bit)){
                    node->put(new Node() , bit);
                }
                node = node->get(bit);
            }
        }

        int findMaxXOR(int num){
            Node* node = root;
            if(!node->get(0) && !node->get(1)) return -1;
            int ans = 0;
            for(int i = 31; i>=0; i--){
                int bit = (num>>i) & 1;
                int revBit = !bit;
                if(node->containsKey(revBit)){
                    ans = ans | (1<<i);
                    node = node->get(revBit);
                }
                else{
                    node = node->get(bit);
                }
            }
            return ans;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<vector<int>> q;
        for(int i = 0; i<n; i++){
            int xi = queries[i][0];
            int mi = queries[i][1];
            q.push_back({mi,xi,i});  // pushing mi first so that sort function will apply in mi
        }

        Trie t;
        
        sort(nums.begin() , nums.end());
        sort(q.begin(),q.end());  // tc O(nlogn)

        vector<int> ans(n);
        int j = 0;

        //TC O(n * 32) + O(nums.size() * 32)
        for(int i = 0; i<n; i++){ 
            int mi = q[i][0];
            int xi = q[i][1];
            int ind = q[i][2];
            while(j < nums.size() && nums[j] <= mi){  //this loop is not running for every iteration of i it just 
                t.insert(nums[j]);
                j++;
            }
            ans[ind] = t.findMaxXOR(xi);
        }
        return ans;
    }
};