 // string is valid palindrome not considering case sensitive
 #include<iostream>
 using namespace std;
    bool isPalin(string str){
        int start = 0;
    int end = str.length();
    for (int i = 0; i<str.length(); i++)
    {
        if(!(str[start]>='a' && str[start]<='z') && !(str[start]>='A' && str[start]<='Z') && !(str[start]>=48 && str[start]<=57)){
            start++;
        }
        else if(!(str[end]>='a' && str[end]<='z') && !(str[end]>='A' && str[end]<='Z') && !(str[end]>=48 && str[end]<=57)){
            end--;
        }
        else{
           if(str[start]!=str[end]){
            return false;
           }
            
        }
        start++;
        end--;
    }
    return true;
    }    
 int main(){
    string str = "race a car";
    if(isPalin(str)){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    
    
    return 0;
 }