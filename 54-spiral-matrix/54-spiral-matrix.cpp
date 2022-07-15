class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
    int row=matrix.size();
        int col=matrix[0].size();
        
        int tne=row*col;
        int count=1;
        int minr=0;
        int maxr=row-1;
        int minc=0;
        int maxc=col-1;
        while(count<=tne){
            
            for(int i=minr,j=minc;j<=maxc;j++){
                ans.push_back(matrix[i][j]);
                count++;
            }
            if(count>tne){
                break;
            }
            minr++;
            for(int i=minr,j=maxc;i<=maxr;i++){
                ans.push_back(matrix[i][j]);
                count++;
            }
                 if(count>tne){
                break;
            }
            maxc--;
            for(int i=maxr,j=maxc;j>=minc;j--){
                   ans.push_back(matrix[i][j]);
                count++;
            }
                 if(count>tne){
                break;
            }
            maxr--;
            for(int i=maxr,j=minc;i>=minr;i--){
                    ans.push_back(matrix[i][j]);
                count++;
            }
                 if(count>tne){
                break;
            }
            minc++;
        }
        return ans;
    }
};