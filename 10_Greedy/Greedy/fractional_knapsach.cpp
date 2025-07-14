// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    static bool cmp(Item a, Item b){
        double t1 = double(a.weight)/a.value;
        double t2 = double(b.weight)/b.value;
        return t1<t2;
        
    }
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr,arr+n,cmp);
        double count = 0.0;
        for(int i = 0; i<n; i++){
            if(arr[i].weight < w){
                count += arr[i].value;
                w -= arr[i].weight;
            }
            else{
                // int remain = w - arr[i].weight;
                count += w*(double(arr[i].value)/double(arr[i].weight));
                break;
            }
        }
        return count;
    }
};