// Appraoch:
// The solution uses a backtracking approach to solve the N-Queens problem. 
// You place queens row by row, and for each row you try all columns. 
// Before placing a queen, the isSafe function checks whether the position is valid by ensuring no other queen exists in the same row, column, or diagonals. 
// If a position is safe, you place the queen and recursively move to the next row. If it leads to a dead end, you backtrack by removing the queen and trying the next column. 
// When all n rows are filled, the current board configuration is added to the result. This systematic exploration guarantees all valid solutions are found.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(vector<string>&board, int row, int col, int n){
        //horizontal
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        // vertical
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        // left diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        // right diagonal
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void nQueens(vector<string> &board,int row,int n,vector<vector<string>> &ans){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j,n)){
                board[row][j]='Q';
                nQueens(board,row+1,n,ans);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>>ans;
        nQueens(board,0,n,ans);
        return ans;
    }
};