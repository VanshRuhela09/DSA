/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();
        if(k>=n) return "0";
        for(auto it : num){
            while(!st.empty() && it<st.top() && k>0){
                st.pop();
                k--;
            }
            st.push(it);
        }
        
        while(k>0){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        
        reverse(ans.begin(),ans.end());
        int i = 0;
        for(i = 0; i<ans.length(); i++){
            if(ans[i]!='0')break;
        }
        string ans2 = ans.substr(i,ans.length()-i);
        
        if(ans2=="") ans2 = "0";
        return ans2;
    }
};