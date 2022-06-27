class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        	int n = cardPoints.size(), totalSum = 0, minSubarray = 0;

        for (int i=0; i<n; i++) {
		totalSum += cardPoints[i];}
        
        int currSum=0;
        
	for (int i=0; i<n; i++) {
		currSum += cardPoints[i];
		if (i < n-k) minSubarray += cardPoints[i];
		else {
			currSum -= cardPoints[i-(n-k)];
			minSubarray = min(minSubarray, currSum);
		}
	}

	return totalSum - minSubarray;
    }
};
