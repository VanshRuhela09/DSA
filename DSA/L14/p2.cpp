 #include<iostream>
using namespace std;
    //Finding pivot first
    int Find(int arr[] , int size , int n){
        int start = 0 , end = size-1 , ans = -1;
        int mid = start + ( end - start )/2;
        while(start<end){
            if(arr[mid]>arr[0]){
                start = mid+1;
            }
            else{
                ans = mid;
                end = mid;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }

    int Findagain(int arr[] , int pivot , int key , int size){
            int end = size -1;
            //shift the start to pivot index
           int start = pivot;
            if(key>=arr[start] && key <= arr[size-1]){
                while(start<=end){
                    int mid = start + (end - start)/2;
                    if(arr[mid]==key){
                        return mid;
                    }
                    else if(key<arr[mid]){
                        end = mid - 1;
                    }
                    else{
                        start = mid + 1;
                    }
                    mid = start + (end-start)/2;
                }
            }
            else{
                int start = 0;
                // shift the end to pivot index
                int end = pivot - 1;
                  while(start<=end){
                    int mid = start + (end - start)/2;
                    if(arr[mid]==key){
                        return mid;
                    }
                    else if(key<arr[mid]){
                        end = mid - 1;
                    }
                    else{
                        start = mid + 1;
                    }
                    mid = start + (end-start)/2;
                }

            }
        return -1;
        
    }
int main(){
    int arr[] = {7,8,9,1,2,3};
    int n;
    cout << "Enter number " << endl;
    cin >> n;
    int a = Find(arr,6,n);
    cout << "Element is at index number " << Findagain(arr , a , n , 6);
    return 0; 
}