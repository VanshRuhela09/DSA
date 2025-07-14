class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1 , sum = 1;
        int peak , down;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum++;
                i++;
            }
            peak = 1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++; // here first peak++ because 1 toh humne prev vale child ko dedi hai so isko 2 se milni start honi chiye
                sum += peak;
                i++;
            }

            down = 1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down; // here first add down becuase down me 1 se start hogi candy milni
                down++;
                i++;
            }
            if(down>peak){
                sum+= (down-peak);  //this extra addition to sum bcs now peak changes as we have greater value of down
            }
        }
        return sum;

        // ==========brute force=======
        // int n = ratings.size();
        // if(n==1){
        //     return 1;
        // }
        // vector<int> left(n,1);
        // vector<int> right(n,1);

        // for(int i = 1; i<n; i++){
        //     if(ratings[i]>ratings[i-1]){
        //         left[i] += left[i-1];
        //     }
        // }

        // for(int i = n-2; i>=0; i--){
        //     if(ratings[i]>ratings[i+1]){
        //         right[i] += right[i+1];
        //     }
        // }
        // int ans = 0;
        // for(int i = 0; i<n; i++){
        //     if(left[i] > right[i]){
        //         ans+=left[i];
        //     }
        //     else{
                
        //         ans+=right[i];
        //     }
        // }
    }
};