// two stack in an array
#include<iostream>
using namespace std;
    class Stack{
        public:
        int top1;
        int top2;
        int size;
        int *arr;
        Stack(int size){
            top1 = -1;
            top2 = size;
            this -> size = size;
            arr = new int[size];
        }
        void push1(int val){
            if(top1 +1==top2 ){
                cout << "stack is full " << endl;
            }
            else{
                top1++;
                arr[top1] = val;
            }
        }

        void push2(int val){
            if(top1 + 1 == top2 ){
                cout << "stack is full " << endl;
            }
            else{
                top2--;;
                arr[top2] = val;
            }
        }

        void pop1(){
            if(top1==-1){
                cout<<"stack is empty" << endl;
            }
            else{
                
                top1--;
                
            }
        }
        void pop2(){
            if(top2==size){
                cout<<"stack is empty" << endl;
            }
            else{
                
                top2++;
                
            }
        }

       
   
    };
int main(){
    Stack s(5);
    s.push1(2);
    s.pop1();
    


    

    return 0;
}