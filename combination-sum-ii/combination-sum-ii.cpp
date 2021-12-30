class Solution {
public:
    
    vector<vector<int>> ans;

void solve(vector<int> v, int target, vector<int> temp, int src) {

	if(src>v.size() || target<0) return; 
	if(!target) {ans.push_back(temp); return;}

	for(int i=src; i<v.size(); i++) {
		if(i>src && v[i]==v[i-1]) continue; //Ignore duplicates
		
		//Backtracking:
		temp.push_back(v[i]);
		solve(v, target-v[i], temp, i+1);//i+1 se looop chalana hai har baar
		temp.pop_back();   
	}

	return;
}
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size(); if(!n) return ans;
	sort(candidates.begin(), candidates.end());
	vector<int> temp;
	solve(candidates, target, temp, 0);

	return ans;
    }
};


