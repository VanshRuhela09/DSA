class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int maxi = INT_MIN;
        while(i<j){
            int h = min(height[i],height[j]);
            int w = j-i;
            int ar = h*w;
            if(ar>maxi){
                maxi = ar;
            }
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxi;
    }
};