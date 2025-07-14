/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
*/
class Solution {
public:
    bool checkValidString(string s) {
        int min=0,max=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min+=1;
                max+=1;
            }
            else if(s[i]==')'){
                min-=1;
                max-=1;
            }
            else{
                min-=1;
                max+=1;
            }
            if(min<0){
                min=0;
            }
            if(max<0){
                return 0;
            }
        }
        return (min==0);
    }
};