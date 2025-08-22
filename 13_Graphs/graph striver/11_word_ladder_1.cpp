/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,0});
        st.erase({beginWord});//marking the element visited

        while(!q.empty()){
            auto f = q.front();
            q.pop();
            string sf = f.first;
            int lev = f.second;
            if(sf == endWord) return lev+1;
            for(char i = 'a'; i<='z'; i++){
                for(int j = 0;j<sf.length(); j++){
                    char orgChar = sf[j];
                    sf[j] = i;
                    if(st.find(sf)!=st.end()){
                            q.push({sf,lev+1});
                            st.erase({sf}); // means mark the element visited
                    }
                    sf[j]=orgChar;
                }
            }
        }
        return 0;
    }
};