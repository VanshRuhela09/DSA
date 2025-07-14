#include<iostream>
using namespace std;
class heap{
    int arr[100];
    int size;
    public:
    heap(){
        size = 0;
        arr[0] = -1;
    }
    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deletion(){
        if(size==0){
            cout<<"nothing";
        }
        arr[1] = arr[size];
        size--;

        // take the root node to the right position
        int i = 1;
        while(i<size){
            int leftIndex = i*2;
            int rightIndex = i*2 + 1;

            if(leftIndex<=size && arr[leftIndex]>arr[i] && arr[leftIndex]<=arr[rightIndex]){
                swap(arr[leftIndex],arr[i]);
                i = leftIndex;
            }
            else if(rightIndex<=size && arr[rightIndex]>arr[i] && arr[rightIndex]>=arr[leftIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else {
                return;
            }
            
        }
    }

    void print(){
        for(int i = 1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

    void heapify(int arr[] , int n , int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if(left<=n && arr[left]>arr[largest]){
            largest = left;
        }
        if(right<=n && arr[right]>arr[largest]){
            largest = right;
        }

        if(largest != i){
           swap(arr[largest],arr[i]);
           heapify(arr,n,largest); 
        }
    }
int main(){
    heap h;
    h.insert(21);
    h.insert(12);
    h.insert(20);
    h.insert(7);
    h.insert(4);

    h.deletion();
    h.print();
    
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i = n/2; i>0; i--){
        heapify(arr,n,i);
    }

    cout<<"printing "<<endl;
    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}