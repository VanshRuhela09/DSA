#include<stdio.h>
void merge(int * arr , int s , int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    int narr1[len1];
    int narr2[len2];
    int mindex = s;
    for(int i = 0; i<len1; i++){
        narr1[i] = arr[mindex++];
    }

    for(int i = 0; i<len2; i++){
        narr2[i] = arr[mindex++];
    }
    
    int index1 = 0;
    int index2 = 0;
    mindex = s;
    while(index1<len1 && index2 < len2){
        if(narr1[index1]<narr2[index2]){
            arr[s++] = narr1[index1++];
        }
        else{
            arr[s++] = narr2[index2++];
        }
    }
    
    while(index1<len1){
        arr[s++] = narr1[index1++];
    }
    while(index2<len2){
        arr[s++] = narr2[index2++];
    }

}
void merge_sort(int * arr , int s , int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    merge_sort(arr , s , mid);

    merge_sort(arr , mid+1 , e);

    merge(arr,s,e);
}
int main(){
    int arr[] = {6,3,4,7,2,8};
    int n = 6;
    merge_sort(arr, 0 , n-1);
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}