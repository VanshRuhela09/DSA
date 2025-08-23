/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        vector<vector<string>> ans;
        set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        
        int level = 0;
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        while(!q.empty()){
            vector<string> top = q.front();
            q.pop();
            string word = top.back();
            if(word == endWord){                   
                ans.push_back(top);
            }
            if(top.size()>level){
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
                level++;
            }
            for(char i = 'a'; i<='z'; i++){
                for(int j = 0; j<word.length(); j++){
                    char origChar = word[j];
                    word[j] = i;
                    if(st.find(word)!=st.end()){
                        top.push_back(word);
                        q.push(top);
                        top.pop_back();
                        usedOnLevel.push_back(word);
                    }
                    word[j] = origChar; 
                }
            }
        }
        return ans;
    }
};