#include<iostream>
using namespace std;
    class Stack{
        public:
        int top;
        int *arr;
        int size;
        Stack(int size){
            this->size = size;
            top = -1;
            arr = new int[size];
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

        void Put_Bottom(int val){
            int count = top;
            if(count == -1){ // can use isEmpty function
                push(val);
                return;
            }
            else{
                count--;
               int temp = peek();
                Put_Bottom(val);
                push(temp);
            }
        }

        void print(){
            for (int i = 0; i < size; i++)
            {
                cout<<arr[i]<<" ";
            }
            
        }
    };
int main(){
    Stack s(5);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(4);
    s.Put_Bottom(99);
    // s.push(9);
    s.print();
    return 0;
}