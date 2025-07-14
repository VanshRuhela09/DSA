#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    bool flag = false;

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
        Trie(){
            root = new Node();
        }
    void insert(string &word){
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(new Node() , word[i]);
            }
            node = node->get(word[i]);
        }
        node->flag = true;
    }

    bool isComplete(string &word){
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            node = node->get(word[i]);
            if(node->flag == false){
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie t;
    for(auto it : a){
        t.insert(it);
    }

    string ans = "";
    for(auto it : a){
        if(t.isComplete(it)){
            if(ans.length() < it.length() || (ans.length() == it.length() && ans > it)){
                ans = it;
            }
        }
    }
    if(ans == "") return "None";
    else return ans;
}