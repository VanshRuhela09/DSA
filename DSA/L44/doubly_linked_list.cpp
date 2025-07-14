#include<iostream>
using namespace std;
    class Node{
        public:
        Node* prev;
        Node* next;
        int data;
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    //insert at head
    void insertAtHead(Node* &head , Node* &tail ,int d){
        Node* temp = new Node(d);
        if(head==NULL){
            head = temp;
            tail = temp;
        }
        else{
        temp->next = head;
        head->prev = temp;
        head = temp;
        }
    }

        // Insert at tail
        void insertAtTail(Node* &head , Node* &tail , int d){
            Node* temp = new Node(d);
             if(tail==NULL){
            tail = temp;
            head = temp;
            }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        } 

        // insert at any position
        void insertAtPos(Node* &head , Node* &tail , int pos , int d){
            Node* NodeToInsert = new Node(d);
            if(pos==1){
                insertAtHead(head,tail,d);
            }
            else{

            Node* temp = head;
            int cnt = 1;
            while(cnt<pos-1){
                temp = temp->next;
                cnt++;
            }

            if(temp->next==NULL){
                insertAtTail(head,tail, d);
            }
            else{
            NodeToInsert->next = temp->next;
            NodeToInsert->prev=temp;
            temp->next->prev = NodeToInsert;
            temp->next = NodeToInsert;
            }

            }
            
        }

        void deleteAtPos(Node* &head , Node* &tail , int pos){
             if(head==NULL){
                cout<<"no data to show"<<endl;
            }
            else{
                Node* temp = head;
                head->prev = NULL;
                
                if(pos==1){

                }
            }
        }

    void print(Node* &head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    int getLength(Node* &head){
        int len = 0;
        Node* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,56);
    print(head);
    cout<<"length is: "<<getLength(head)<<endl;

    cout<<endl;

    insertAtHead(head,tail,456);
    print(head);
    cout<<"length is: "<<getLength(head)<<endl;
    cout<<endl;

    insertAtTail(head,tail,3000);
    print(head);
    cout<<"length is: "<<getLength(head)<<endl;

    cout<<endl;

    insertAtPos(head , tail, 1 , 700);
    print(head);
    cout<<"length is: "<<getLength(head)<<endl;
    cout<<endl;
    insertAtPos(head , tail, 5 , 1500);
    print(head);
    cout<<"length is: "<<getLength(head)<<endl;

    cout<<endl;
    deleteAtPos(head,tail,2);
    print(head);
    cout<<"length is: "<<getLength(head)<<endl;

    cout<<endl;
    deleteAtPos(head,tail,1);
    print(head);
    cout<<"length is: "<<getLength(head)<<endl;
    deleteAtPos(head,tail,1);
    print(head);
    cout<<"length is: "<<getLength(head)<<endl;
    deleteAtPos(head,tail,1);
    print(head);
    cout<<"length is: "<<getLength(head)<<endl;
    deleteAtPos(head,tail,1);
    print(head);
    cout<<"length is: "<<getLength(head)<<endl;


    return 0;
}