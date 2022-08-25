class Solution {
public:
    //from pep
    //calculate next greater on right and store it in map
    vector<int> nge;
vector<int> nextGreaterRight(vector<int> &arr)
{
  int n = arr.size();
  nge.resize(n, 0);
  nge[n - 1] = -1;
  stack<int>st;
  st.push(arr[n - 1]);
  for (int i = n - 2; i >= 0; i--)
  {
    while (st.size() > 0 && st.top() <= arr[i])
    {
      st.pop();
    }
    if (st.size() == 0)
    {
      nge[i] = -1;
    }
    else {
      nge[i] = st.top();
    }
    st.push(arr[i]);
  }
  return nge;
}
    

    vector<int> nextGreaterElement(vector<int>& query, vector<int>& nums) {
         //Getting values of NGR
    vector<int> ngr = nextGreaterRight(nums);
    
    //Creating an unordered map
    unordered_map<int,int> mp;
    
    //Fill the unordered map
    for(int i=0 ;i<nums.size();i++)
    {
        mp.insert({nums[i],ngr[i]});
    }
    
    //Create an ans vector
    vector<int> ans(query.size());
    
    //Fill the ans VECTOR
    for(int i=0; i<query.size(); i++)
    {
        ans[i] = mp.at(query[i]);
    }
    return ans;
    }
};