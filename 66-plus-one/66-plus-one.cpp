class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        if(digits.size()==1){
            if(digits[0]==9){
                vector<int>ans={1,0};
                
                // ans.push_back(0);
                return ans;
            }
            else{
              digits[0]+=1;
                  return digits;
            }
        }
        int n=digits.size();
        for (int i = n - 1; i >= 0; --i)
	{
		if (digits[i] == 9)
		{
			digits[i] = 0;
            if(i==0){
                digits.insert(digits.begin(),1);
                return digits;
            }
		}
		else
		{
			digits[i]++;
			return digits;
		}
	}
        return digits;
        
        
    }
};