#include <bits/stdc++.h> 
bool isSafe(int row , int col , vector<vector<int>>& sudoku , int val){
    for(int i = 0; i<sudoku.size(); i++){
        if(sudoku[row][i]==val){
            return false;
        }

        if(sudoku[i][col]==val){
            return false;
        }

        if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& sudoku){
    int size = sudoku[0].size();
    
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            if(sudoku[i][j]==0){
                for(int val = 1; val<=9; val++){
                    if(isSafe(i , j , sudoku , val)){
                        sudoku[i][j] = val;
                       bool aage = solve(sudoku);
                    if(aage){
                        return true;
                    } 
                    else{
                        //backtracking
                        sudoku[i][j] = 0;
                    }
                    }
                    
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix

    solve(sudoku);
}