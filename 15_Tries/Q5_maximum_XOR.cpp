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
            for(int i = 31; i>=0;i--){
                int bit = (num>>i) & 1;
                if(!node->containsKey(bit)){
                    node->put(new Node() , bit);
                }
                node = node->get(bit);
            }
        }

        int findMaxXOR(int num){
            //this function will find the max xor of a number with the nums array
            int ans = 0;
            Node* node = root;
            for(int i = 31; i>=0; i--){
                int bit = (num>>i) & 1;
                int revBit = !bit;
                if(node->containsKey(revBit)){
                    // if we get reverse bit then only set the ith bit as 1 of ans
                    ans = ans | (1<<i);
                    node = node->get(revBit);
                }
                else{
                    // if we don't get the reverse bit then we don't have to set anything in ans bcs humko same bit mili hai toh xor 0 hi hoga same bit ka.
                    node = node->get(bit);
                }
            }
            return ans;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(int it : nums){
            t.insert(it);
        }
        int maxAns = INT_MIN;
        for(auto it : nums){
            maxAns = max(maxAns , t.findMaxXOR(it));
        }
        return maxAns;
    }
};