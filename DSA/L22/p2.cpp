// reverse word in string
#include<iostream>
#include<cstring>
using namespace std;
    string reverse(string s){
        string temp = "";
        int count = 0;
        for (int i = 0; i<s.length(); i++)
        {
            if(s[i]==' '){
                count++;
            }
        }
        int p = 0;
        s.push_back(' ');
            int k = 0;
        for (int i = 0; i <=count; i++)
        {
            string temp2 = "";
            for (int j = 0; s[k]!=' ' ; j++)
            {
                temp2.push_back(s[k]);
                k++;
            }
            k++;

            
            for (int i = temp2.length() - 1; i>=0; i--)
            {
                temp.push_back(temp2[i]);
            }

           if(p!=count){
             temp.push_back(' ');
             p++;
            }
            
        }
        return temp;
       
        
        
    }
int main(){
    string s = "the sky is blue";
    cout << reverse(s);
    return 0;
}