#include<stdio.h>


int partition(int arr[],int s,int e)
{
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            cnt++;
        }
    }

    int pivotIndex=s+cnt;

    int temp;
    temp=arr[pivotIndex];
    arr[pivotIndex]=arr[s];
    arr[s]=temp;


    int i=s,j=e;

    while(i<pivotIndex && j>pivotIndex)
    {
        if(arr[i]<arr[pivotIndex])
        {
            i++;
        }
        if(arr[j]>arr[pivotIndex])
        {
            j--;
        }
        if(i<pivotIndex && j>pivotIndex)
        {
        int temp;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        }
    }
    return pivotIndex;
}



void quick_sort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return;
    }

    int p=partition(arr,s,e);

    quick_sort(arr,s,p-1);
    quick_sort(arr,p+1,e);
}

int main()
{
    int arr[7]={1,9,3,4,5,6,7};
    int n=7;

    quick_sort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}