class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int size = matrix.size();
	    
        // this for loop is for bcs question me int_max ki jagah -1 use kia hai toh usko INT_MAX banaya hai
	    // for(int i = 0; i<size; i++){
	    //     for(int j = 0; j<size; j++){
    	//         if(matrix[i][j] == -1){
    	//             matrix[i][j] = 1e9;
    	//         } 
	    //     }
	    // }
	    
	    for(int via = 0; via<size; via++){
	        
	        for(int i = 0; i<size; i++){
	            for(int j = 0; j<size; j++){
	                int mini = min(matrix[i][j] , matrix[i][via] + matrix[via][j]);
	                    matrix[i][j] = mini;
	            }
	        }
	        
	    }
	    
        // now this loop is for to conver INT_MAX to -1 according to question

	    // for(int i = 0; i<size; i++){
	    //     for(int j = 0; j<size; j++){
    	//         if(matrix[i][j] == 1e9){
    	//             matrix[i][j] = -1;
    	//         } 
	    //     }
	    // }
	}
};