// maximum occuring character whose ascii value of lesser
#include<iostream>
using namespace std;
    char coun(string s){
        int max=0;
        char ret;
        for (int i = 0; i < s.length(); i++)
        { 
            int count = 0;
            if(s.at(i)!='0'){
                char temp = s.at(i);
                for (int j = i; j < s.length(); j++)
                {
                    if(temp==s.at(j)){
                        count++;
                        s.at(j) = '0';
                    }
                }
                if(count>max){
                    max = count;
                    ret = temp;
                }
                else if(count==max){
                    if(int(temp)<int(ret)){
                        ret = temp;
                    }
                   
                }
                
            }
        }
        return ret;

    }
int main(){
    string s = "testsample";
    cout << coun(s);
    return 0;
}