#include<iostream>
#include<unordered_map>
#include<list>
#include<map>
using namespace std;
class graph{
    public:
    unordered_map<int , list<int>> adj;
    void addEdge(int u , int v , bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i : adj){
            cout<<i.first<<" - ";
            for(auto j : i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    
    graph g;
    int n;
    cout<<"enter number of edges " ;
    cin>>n;
    for(int i = 0; i<n; i++){
        int u , v;
        cout<<"enter u and v : ";
        cin>>u;
        cin>>v;
        g.addEdge(u,v,0);
    }

    g.print();
    
    
    return 0;
}