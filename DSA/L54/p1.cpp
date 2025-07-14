#include<iostream>
using namespace std;
    class Stack{
        public:
        int *arr;
        int top;
        int size;
        Stack(int size){
            this -> size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int val){
            if(top>=size-1){
                cout<<"stack is full"<<endl;

            }
            else{
                top++;
                arr[top] = val;
            }
        }

        void pop(){
            if(top==-1){
                cout<<"array is not empty"<<endl;
            }
            else{
                top--;
            }
        }

        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        
        int peek(){
            if(top==-1){
                return -1;
            }
            else{
                int temp = arr[top];
                top--;
                return temp;
            }
        }
    };
int main(){
   Stack s(4);
   s.push(3);
   s.push(4);
   s.push(8);
   cout<<s.peek() << " ";
   cout<<s.peek() << " ";
   if(s.isEmpty()){
    cout<<"stack is empty" <<endl;
   }
   else{
    cout<<"stack is not empty" <<endl;
   }
    return 0;
}