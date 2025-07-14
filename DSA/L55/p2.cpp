//delete middle element
#include<iostream>
using namespace std;
    class Stack{
        public:
        int top;
        int* arr;
        int size;
        int count = 0;
        Stack(int size){
            this->size = size;
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

        void mid_del(){
            int mid = size/2;
            if(count == mid){
                pop();
                return ;
            }
            else{
                count++;
                int temp = peek();
                mid_del();
                push(temp);
            }
            

        }

        void print(){
            for (int i = 0; i <=top; i++)
            {
                cout<<arr[i]<<" ";
            }
            
        }

    };
int main(){
        Stack s(6);
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.push(7);
        cout<<"Before delete"<<endl;
        s.print();
        cout<<"After delete" << endl;
        s.mid_del();
        s.print();

    return 0;
}