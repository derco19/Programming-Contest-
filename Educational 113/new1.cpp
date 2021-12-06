// Find the minimum cost path from top left to bottom right of a 2-D matrix
/*
{{7,1,3,5},
 {2,3,6,1},
 {6,1,7,2},
 {6,6,7,1}}
*/

#include <bits/stdc++.h>
using namespace std;

int min_path_sum(vector <vector <int>> &matrix){

    int n=matrix.size();
    int m=matrix[0].size();
    // vector <vector <int>> matrix_dp(n+1,vector <int>(m+1,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                if(j==0)
                continue;
                else{
                    matrix[i][j]+=matrix[i][j-1];
                }
            }
            else{
                if(j==0){
                    matrix[i][j]+=matrix[i-1][j];
                }
                else{
                    matrix[i][j]=matrix[i][j]+min(matrix[i-1][j],matrix[i][j-1]);
                }
            }
        }
    }

    return matrix[n-1][m-1];

}

int main(){
    vector <vector <int>> 
    V={
        {7,1,3,5},
        {2,3,6,1},
        {6,1,7,2},
        {6,6,7,1}
    };
    cout<<min_path_sum(v)<<"\n";
}
