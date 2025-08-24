/*
A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
So, 'c' → 'a' → 'b' is a valid ordering.
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
*/

class Solution {
  public:
    string topo(unordered_map<char,vector<char>> &adj , vector<int> &present){
        vector<int> indegree(26);

        for(auto it : adj){
            for(auto i : it.second){
                indegree[i - 'a']++;
            }
        }
        queue<int> q;
        for(int i = 0; i<26; i++){
            if(indegree[i]==0 && present[i] == 1){
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()){
            int f = q.front();
            char ch = f + 'a';
            ans += ch;
            q.pop();
            for(auto it : adj[ch]){
                indegree[it - 'a']--;
                if(indegree[it - 'a']==0){
                    q.push(it - 'a');
                }
            }
            
        }
        return ans;
    }
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char,vector<char>> adj;
        vector<int> present(26);
        
        set<char> sett;
        for(auto it : words){
            for(auto i : it){
                sett.insert(i);
                present[i - 'a'] = 1;
            }
        }
        for(int i = 0; i<words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int l1 = s1.length();
            int l2 = s2.length();
            int j = 0;
            while(j<l1 && j<l2){
                if(s1[j]!=s2[j]){
                    adj[s1[j]].push_back(s2[j]);
                    break;
                }
                j++;
            }
            if(j==l2 && l1>l2){
                return "";
            }
            
        }
        string ans = topo(adj,present);
        if(ans.length()!=sett.size()){
            return "";
        }
        return ans;
    }
};