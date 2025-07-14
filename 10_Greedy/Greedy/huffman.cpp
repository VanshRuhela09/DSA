class node{
    public:
    node* left;
    node* right;
    int data;
    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class cmp{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};
class Solution
{
	public:
	
	void traverse(vector<string> &ans , node* n , string s){
	    if(n->left==NULL && n->right==NULL){
	        ans.push_back(s);
	        return;
	    }
	    traverse(ans , n->left,s+'0');
	    traverse(ans,n->right,s+'1');
	}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<node* , vector<node*> , cmp > pq;
		    for(int i =0; i<N; i++){
		        node* temp = new node(f[i]);
		        pq.push(temp);
		    }
		    int j = S.length()-1;
		    while(pq.size()>1){
		        node* left = pq.top();
		        pq.pop();
		        
		        node* right = pq.top();
		        pq.pop();
		        
		        node* temp1= new node(left->data + right->data);
		        temp1->left = left;
		        temp1->right = right;
		        pq.push(temp1);
		    }
		       
		    node* temp2 = pq.top();
		    pq.pop();
		    vector<string> ans;
		    traverse(ans,temp2,"");
		    
		    return ans;
		}
};