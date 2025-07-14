#include<stdio.h>
int main(){
    int arr[] = {6,2,3,9,1,0};
    int n = 6;
    int i = 1;
    while(i<n){
        int temp = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
        i++;
    }

    for(int i =0 ;i<n ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}