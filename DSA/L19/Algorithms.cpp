#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> v1;
   v1 = {1,2,6,7,3,3,3,4,5,6,7,8,9};
   // Binary search
    cout << binary_search(v1.begin() , v1.end() , 3) << endl; 

    //lower and upper bound
    vector<int> :: iterator it = lower_bound(v1.begin() , v1.end() , 3);
    vector<int> :: iterator i = upper_bound(v1.begin() , v1.end() , 3);
    cout << *it << " " << *i;
    cout << endl;

    // max() min()
    int a = 2 , b = 3;
    cout << "max element" << max(a,b)<< endl << "min element: " << min(a,b) << endl;

    //Reverse
    string s = "abcde";
    reverse(s.begin() , s.end());
    cout << "reversed string is :" << s << endl;

    //rotate
    rotate(v1.begin() , v1.begin() + 2 , v1.end() );
    cout << "rotated vector is :";
    for(auto i : v1){
        cout << i << " ";
    }
    cout << endl;

    //sort
    sort(v1.begin() , v1.end());
    cout << "sorted vector is : " ;
    for(auto i : v1){
        cout << i << " ";
    }
    return 0;
}