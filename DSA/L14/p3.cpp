// find the root of given number by binary search
#include<iostream>
  long long int Find_root(int n){
       long long int start = 1 , end = n , ans = -1;
       long long int mid = start + ( end - start)/2;
        while(start<=end){
            if((mid*mid) ==n){
                return mid;
            }
            else if((mid*mid)>n){
                end = mid - 1;;
            }
            else{
                ans = mid;
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
//    long long int Find_root(int n){
//         int start = 0 , end = n, ans = -1;
//        long long int mid = start + (end - start)/2;
//         while(start<=end){
//                 long long int sqr = mid*mid;
//             if(sqr==n){
//                 return mid;
//             }
//             else if(sqr>n){
//                 end = mid - 1;
//             }
//             else{
//                 ans = mid;
//                 start = mid + 1;
//             }
//             mid = start + ( end - start )/2;
//         }
//     }

    double correct_root(int root , int n , int pre){
        double fac = 1;
        double ans = root;
        for (int i = 0; i <pre; i++)
        {
             fac =  fac/10;
             //
            for (double j = ans ; j*j<n ; j = j + fac)
            {
                ans = j;
            }

            // for (int i = 0; i < pre; i++)
        // {
        //     t = t-fac;
        //     fac = fac/10;
        //     for (int j = 0; t*t<n; j++)
        //     {
        //         t = t + fac;
        //     }
            
        // }

        }
        return ans;
        
    }
using namespace std;
int main(){
    int n;
    cout << "Enter number " << endl;
    cin >> n;
    int root = Find_root(n);
    cout << "root is : " << correct_root(root , n , 3);
    return 0;
}