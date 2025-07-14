struct Node{
    Node* links[26];

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(Node* node , char ch){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
};

class Trie{
    private:
        Node* root;
    public:
        int count = 1;
        Trie(){
            root = new Node();
        }
        void insert(string &word){
            Node* node = root;
            for(int i = 0;i<word.length(); i++){
                if(!node->containsKey(word[i])){
                    count++;
                    node->put(new Node() , word[i]);
                }
                node = node->get(word[i]);
            }
        }
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Trie t;
    for(int i = 0; i<s.length(); i++){
        string sub = s.substr(i);
        t.insert(sub);
    }
    return t.count;
}