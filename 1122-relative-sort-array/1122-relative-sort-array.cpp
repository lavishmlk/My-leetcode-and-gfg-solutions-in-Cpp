class Solution {
public:
    //cknk
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // taking res vector to store the result elements
        vector<int> res;
        
        // taking a map to store the frequency of elements of arr1, and not taking unordered_map bcz, we want it to store in a ascending order, so map will store into ascending order
        map<int, int> mp;
        
        // store the frequency of elements of arr1
        for(auto a : arr1){
            mp[a]++;
        }
        
        // iterating over arr2, and
        // checking if element of arr2 is present into mp, then simple taking its frequency and adding the number that much time into the result
        // in last delete that element from mp
        for(auto a : arr2){
            if(mp[a]){
                int count = mp[a];
                
                for(int jtr = 0; jtr < count; jtr++){
                    res.push_back(a);
                }
                
                mp.erase(a);
            }
        }
        
        // add the remaining elements left in mp into res vector
        for(auto m : mp){
            int count = m.second;
            for(int jtr = 0; jtr < count; jtr++){
                res.push_back(m.first);
            }
        }
        
        return res;
    }
};