// Time: O(N) since each element is processed (add/remove) at most twice.
// Space: O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int>ans;
        deque<int>q;
        
        for(int i=0;i<k;i++){
              if(q.size()==0){
                q.push_back(nums[i]);
                continue;
            }
            while(q.size()>0 && q.back()<nums[i]){
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        ans.push_back(q.front());
        for(int i=k;i<nums.size();i++){
            if(q.front()==nums[i-k]){
                q.pop_front();
            }
               while(q.size()>0 && q.back()<nums[i]){
                q.pop_back();
            }
             q.push_back(nums[i]);
            
                ans.push_back(q.front());
        }
        return ans;
    }
};

//using pq
//tc-n*logK (where k is size of heap but k can be equal to N in worst case lke eg=> 1,2,3,4,5)
//sc-O(n) in worst case
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
//         // create a priority queue (Max Heap) of pair of int
//         // first of the pair is the element of the array
//         // and second is the index
//         priority_queue<pair<int,int>> p;
     
//         vector<int>res;
//         // add all the elements in the first window to the PQ
//         for(int i = 0; i < k; i++)
//             p.push({arr[i],i});
//         // add the max element of first window to the res vector
//         res.push_back(p.top().first);
//         // start iteration from the second window
//         for(int i = k; i < arr.size(); i++)
//         {
//             // add the element into the PQ
//             p.push({arr[i],i});
//             // remove all the elments which are not in the current window
//             // current window is from [i-k+1 , i]
//             while(p.top().second <=i-k)
//                 p.pop();
//             // add the max element in the PQ to the res
//             res.push_back(p.top().first);
//         }
//         // return the result
//         return res;
        
//     }
// };