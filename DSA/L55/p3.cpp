// valid paranthesis
#include<iostream>
using namespace std;
    class Stack{
        public:
        int top;
        char *arr;
        int size;
        Stack(int size){
            this->size = size;
            arr = new char[size];
            top = -1;
        }

        void push(char val){
            if(top>=size){
                cout<<"full"<<endl;
            }
            else{
                top++;
                arr[top] = val;

            }
        }

            void pop(){
                if(top==-1){
                    cout<<"empty"<<endl;
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

            bool check(string str){
                for (int i = 0; i < str.length(); i++)
                {
                    if(str.at(i)==')'||str.at(i)=='}'||str.at(i)==']'){
                        if(isEmpty()){
                            return false;
                        }
                        else{
                            if((str.at(i)=='}' && arr[top]=='{') || (str.at(i)==']' && arr[top]=='[') || (str.at(i)==')' && arr[top]=='(')){
                                pop();
                            }
                            else{
                                return false;
                            }
                        }
                    }
                    else{
                        push(str.at(i));
                    }
                }
                if(isEmpty()){
                    return true;
                }
                else{
                    return false;
                }
            }
    };
int main(){
    string str = "[(])";
    Stack s(100);
    if(s.check(str)){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"not balanced"<<endl;
    }
    
    return 0;
}