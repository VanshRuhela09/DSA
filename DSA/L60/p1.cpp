//implementation of double ended queue 100% working
#include<iostream>
using namespace std;

    void push_back(int val , int arr[] , int* f , int* r , int size){
        if((*f)==((*r)+1)%size){
            cout<<"queue is full"<< endl;
        }
        else{
            if(*f==-1){
                *f = ((*f)+1)%size;
                *r = ((*r)+1)%size;
                arr[*r] = val;
            }
            else{
                (*r) = ((*r)+1)%size;
                arr[*r]=val;
            }
        }
    }

    int pop_back(int arr[] , int size , int* f , int* r){
        int temp;
        if(*f==-1){
            cout<<"stack is empty" << endl;
            return -1;
        }
        else{
            if(*r==*f){
                temp = arr[*r];
                (*f)=-1;
                (*r)=-1;
                return temp;

            }
            else{
                    int temp = arr[*r];
                if((*r)-1==-1){
                    *r = size-1;
                }
                else{
                (*r)--;

                }
                return temp;

            }
        }
    }

    void Push_front(int arr[] , int size , int* f , int* r , int val){
        if((*f)==((*r)+1)%size){
            cout<<"queue is full" << endl;
        }
        else{
            if(*f==-1){
                *f = ((*f)+1)%size;
                *r = ((*r)+1)%size;
                arr[*f] = val;
            }
            else{
                *f = ((*f)-1)%size;
                if(*f=-1){
                    *f = size-1;
                }
                arr[*f] = val;
            }
        }
    }

    int Pop_front(int arr[] , int size , int* f, int *r){
        if(*f==-1){
            cout<<"queue is empty" << endl;
        return -1;
        }
        else{
            if(*f==*r){
                int temp = arr[*f];
                *f=-1;
                *r=-1;
                return temp;
            }
            else{
                int temp = arr[*f];
                *f = ((*f)+1)%size;
                return temp;
            }
        }
    }
    int front(int arr[], int *f){
        return arr[*f];
    }
    int back(int arr[], int *r){
        return arr[*r];
    }

int main(){
    int arr[100];
    int f = -1;
    int r = -1;
    // push_back(4,arr,&f,&r,5);
    // push_back(3,arr,&f,&r,5);
    // push_back(7,arr,&f,&r,5);
    // cout<<"Front is :"<<front(arr,&f)<<endl;
    // cout<<"back is :" <<back(arr,&r)<<endl;
    // cout<<endl;

    // Push_front(arr,5,&f,&r , 9);
    // cout<<"Front is :"<<front(arr,&f)<<endl;
    // cout<<"back is :" <<back(arr,&r)<<endl;
    // cout<<endl;

    // cout<<"removed element :" <<Pop_front(arr,5,&f,&r)<<endl;
    // cout<<"Front is :"<<front(arr,&f)<<endl;
    // cout<<"back is :" <<back(arr,&r)<<endl;
    // cout<<endl;

    // cout<<"removed element is :"<<pop_back(arr , 5 , &f , &r)<<endl;
    // cout<<"Front is :"<<front(arr,&f)<<endl;
    // cout<<"back is :" <<back(arr,&r)<<endl;
    // cout<<endl;
    
    push_back(3,arr,&f,&r,5);
    push_back(10,arr,&f,&r,5);
    push_back(7,arr,&f,&r,5);
    push_back(9,arr,&f,&r,5);
    cout<<"removed element :" <<Pop_front(arr,5,&f,&r)<<endl;
    cout<<"removed element :" <<Pop_front(arr,5,&f,&r)<<endl;
    cout<<"removed element :" <<Pop_front(arr,5,&f,&r)<<endl;
    push_back(10,arr,&f,&r,5);
    push_back(7,arr,&f,&r,5);
    push_back(9,arr,&f,&r,5);
    push_back(25,arr,&f,&r,5);
    cout<<"removed element is :"<<pop_back(arr , 5 , &f , &r)<<endl;
    cout<<"removed element is :"<<pop_back(arr , 5 , &f , &r)<<endl;
    cout<<"removed element is :"<<pop_back(arr , 5 , &f , &r)<<endl;
    cout<<"removed element is :"<<pop_back(arr , 5 , &f , &r)<<endl;
    cout<<"removed element is :"<<pop_back(arr , 5 , &f , &r)<<endl;
    return 0;
}