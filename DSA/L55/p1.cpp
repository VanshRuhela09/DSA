//reverse stack
#include<iostream>
using namespace std;
     class Stack{
        public:
        char *arr;
        int top;
        int size;
        string str = "";
        Stack(int size){
            this -> size = size;
            arr = new char[size];
            top = -1;
        }

        void push(char val){
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

        
        
        char peek(){
            if(top==-1){
                return -1;
            }
            else{
               char temp = arr[top];
               top--;
               return temp;
            }
        }
        void cpy(int len){
            for (int i = 0; i < len; i++)
            {
                str.push_back(peek());
            }
            
        }

        void print(){
            cout<<str;

         }
       
    };
int main(){
    string str = "hello";
    Stack s(5);
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    
    s.cpy(str.length());
    s.print();
    
    return 0;
}