// singly linked list
#include<iostream>
using namespace std;
    class Node{
        public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next=NULL;
        }

        // ~Node(){
        //     cout<<"destructor called"<<endl;
        //     if(this->next!=NULL){
        //         delete this->next;
        //         this->next = NULL;
        //         cout<<"chalne ka ni"<<endl;
        //     }
        // }

    };
        // insert at head
        void InsertAtHead(Node* &head , Node* &tail , int d){
            Node* temp = new Node(d);
            if(head==NULL){
                head = temp;
                tail = temp;
            }
            else{
            temp->next=head;
            head = temp;
            }
        }

        // insert at tail
        void InsertAtTail(Node* &head , Node* &tail , int b){
            Node* temp = new Node(b);
            if(tail==NULL){
                tail = temp;
                head = temp;
            }
            else{
            tail->next = temp;
            tail = temp;
            }
        }

        // insert at some position
        void InsertaAtpos(Node* &head , Node* &tail ,int pos, int d){
            Node* NodeToInsert = new Node(d);
            if(pos==1){
                InsertAtHead(head,tail,d);
            }
            else{
            int cnt = 1;
            Node* temp = head;
            while(cnt<pos-1){
                temp = temp->next;
                cnt++;
            }
            if(temp->next==NULL){
                InsertAtTail(head,tail,d);
            }
            else{
            NodeToInsert->next = temp->next;
            temp->next = NodeToInsert;
            }
            }
        }
        // deleting the node
        int deleteAtPos(int pos , Node* &head , Node* &tail){
            if(head==NULL){
                cout<<"no data to delete"<<endl;
            }
            else if(pos==1){
                int val = head->data;
                Node* temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp;
                return val;
            }
            else{
            Node* current = head;
            Node* prev = NULL;
                int cnt = 1;
                while(cnt<pos){
                    prev = current;
                    current = current->next;
                    cnt++;
                }
                int s = current->data;
                prev->next = current->next;
                if(prev->next==NULL){   
                    tail = prev;
                }
                current->next = NULL;
                delete current;
                return s;
            }

        }

        //printing the linked list
        void print(Node* &head){
            if(head==NULL){
                cout<<"no data to show"<<endl;
            }
            else{

             Node* temp = head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
            }
        }
        
int main(){
    // Node* node1 = new Node(3);
    // Node * head = node1;
    // Node* tail = node1;

    Node* head = NULL;
    Node* tail = NULL;
    InsertAtHead(head,tail,4);
    print(head);

    InsertAtHead(head,tail,0);
    print(head);

    InsertAtTail(head,tail , 6);
    print(head);

    InsertAtTail(head,tail , 78);
    print(head);

    InsertaAtpos(head,tail,3,89);
    print(head);

    InsertaAtpos(head,tail,6,785);
    print(head);

    InsertaAtpos(head,tail,7,1024);
    print(head);

    cout<<"tail is " <<tail->data<<endl;

    cout<<endl;

    cout<<"deleted value is "<<deleteAtPos(1,head,tail)<<endl;
    cout<<"after deleted"<<endl;
    print(head);
    cout<<"head is at "<<head->data<<endl;

    cout<<endl;

    cout<<"deleted value is "<<deleteAtPos(5,head,tail)<<endl;
    cout<<"after deleted"<<endl;
    print(head);
    cout<<"tail is at "<<tail->data<<endl;

    cout<<endl;

    cout<<"deleted value is "<<deleteAtPos(1,head,tail)<<endl;
    cout<<"after deleted"<<endl;
    print(head);
    cout<<"head is at "<<head->data<<endl;
    cout<<"tail is at "<<tail->data<<endl;
    cout<<endl;
    cout<<"deleted value is "<<deleteAtPos(1,head,tail)<<endl;
    cout<<"after deleted"<<endl;
    print(head);
    cout<<"tail is at "<<head->data<<endl;
    cout<<endl;
    cout<<"deleted value is "<<deleteAtPos(1,head,tail)<<endl;
    cout<<"after deleted"<<endl;
    print(head);
    cout<<"tail is at "<<head->data<<endl;
    cout<<endl;
    cout<<"deleted value is "<<deleteAtPos(1,head,tail)<<endl;
    cout<<"after deleted"<<endl;
    print(head);
    cout<<"tail is at "<<head->data<<endl;
    cout<<endl;
    cout<<"deleted value is "<<deleteAtPos(1,head,tail)<<endl;
    cout<<"after deleted"<<endl;
    print(head);
   


    return 0;
}
/*
this is the code when starting node are created by constructor 
starting value of head and tail is not NULL
// singly linked list
#include<iostream>
using namespace std;
    class Node{
        public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next=NULL;
        }

        ~Node(){
            cout<<"destructor called"<<endl;
            if(this->next!=NULL){
                delete this->next;
                this->next = NULL;
                cout<<"chanlen ka ni"<<endl;
            }
        }

    };
        // insert at head
        void InsertAtHead(Node* &head , int d){
            Node* temp = new Node(d);
            temp->next=head;
            head = temp;
        }

        // insert at tail
        void InsertAtTail(Node* &tail , int b){
            Node* temp = new Node(b);
            tail->next = temp;
            tail = temp;
        }

        // insert at some position
        void InsertaAtpos(Node* &head , Node* &tail ,int pos, int d){
            Node* NodeToInsert = new Node(d);
            if(pos==1){
                InsertAtHead(head,d);
            }
            else{
            int cnt = 1;
            Node* temp = head;
            while(cnt<pos-1){
                temp = temp->next;
                cnt++;
            }
            if(temp->next==NULL){
                InsertAtTail(tail,d);
            }
            else{
            NodeToInsert->next = temp->next;
            temp->next = NodeToInsert;
            }
            }
        }
        // deleting the node
        int deleteAtPos(int pos , Node* &head , Node* &tail){
            if(pos==1){
                int val = head->data;
                Node* temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp;
                return val;
            }
            else{
            Node* current = head;
            Node* prev = NULL;
                int cnt = 1;
                while(cnt<pos){
                    prev = current;
                    current = current->next;
                    cnt++;
                }
                int s = current->data;
                prev->next = current->next;
                if(prev->next==NULL){   
                    tail = prev;
                }
                current->next = NULL;
                delete current;
                return s;
            }

        }

        //printing the linked list
        void print(Node* &head){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        
int main(){
    Node* node1 = new Node(3);
    // cout<<a->data<<endl;
    // cout<<a->next;
    Node * head = node1;
    Node* tail = node1;
    InsertAtHead(head,4);
    print(head);

    InsertAtHead(head,0);
    print(head);

    InsertAtTail(tail , 6);
    print(head);

    InsertAtTail(tail , 78);
    print(head);

    InsertaAtpos(head,tail,3,89);
    print(head);

    InsertaAtpos(head,tail,7,785);
    print(head);

    InsertaAtpos(head,tail,8,1024);
    print(head);

    cout<<"tail is " <<tail->data<<endl;

    cout<<endl;

    cout<<"deleted value is "<<deleteAtPos(1,head,tail)<<endl;
    cout<<"after deleted"<<endl;
    print(head);
    cout<<"head is at "<<head->data<<endl;

    cout<<endl;

    cout<<"deleted value is "<<deleteAtPos(5,head,tail)<<endl;
    cout<<"after deleted"<<endl;
    print(head);
    cout<<"tail is at "<<tail->data<<endl;

    cout<<endl;

    cout<<"deleted value is "<<deleteAtPos(6,head,tail)<<endl;
    cout<<"after deleted"<<endl;
    print(head);
    cout<<"tail is at "<<tail->data<<endl;

    return 0;
}
*/