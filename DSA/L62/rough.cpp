#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildtree(node* root){
    cout<<"enter data"<<endl;
    int data;
    cin>>data;
    if(data==-1){
    return NULL;
    }
    

}

int main(){
    
    return 0;
}