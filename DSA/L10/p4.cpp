// find duplicate from array containing values from 1 to n-1
#include <iostream>
using namespace std;
int find_dup(int arr[], int size)
{
    int ans1 = 0,ans2=0;
    for (int i = 0; i < size; i++)
    {
        ans1 = ans1 ^ arr[i];
        cout<<ans1<<" ";
    }
    cout<<endl;
    for (int i = 1; i < size; i++)
    {
        ans2 = ans2 ^ i;
        cout<<ans2<<" ";
    }
    cout<<endl;
    return ans1^ans2;
}
int main()
{
    int arr[6] = {5, 1, 2, 3, 4, 2};
    cout << "duplicate elemtent is :" << find_dup(arr, 6) << endl;
    return 0;
}