//unique number of occurrence
//using unordered map
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> v){
 unordered_map<int,int> ump;
    
    for(auto x : v){
        ump[x] = 0;
    }
    for(int i = 0; i<v.size(); i++){
        int count = 1;
        for(int j = i+1; j<v.size(); j++){
            if(v[i]==v[j]){
                count++;
            }
        }
        if(count>ump[v[i]]){
            ump[v[i]] = count;
        }
    }

    for(auto x : ump){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;

    for(auto x: ump){
        for(auto y : ump){
            if(x.first!=y.first && x.second==y.second){
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector<int> v{1,2,3,1,3,1,2};
   if(check(v)){
    cout<<"have unique occurence"<<endl;
   }
   else{
    cout<<"not have same occurence"<<endl;
   }
    return 0;
}