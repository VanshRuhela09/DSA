#include<iostream>
#include<queue>
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
node* build(node* root){
    cout<<"enter data"<<endl;
    int val;
    cin>>val;
    root = new node(val);
    if(val==-1){
        return NULL;
    }
    cout<<"enter data for left of "<<val<<endl;
    root->left = build(root->left);
    cout<<"enter data for right "<<val<<endl;
    root->right = build(root->right);
    return root;
}
void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int main(){
    // 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    node* root = NULL;
    root = build(root);
    levelOrder(root);
    return 0;
}