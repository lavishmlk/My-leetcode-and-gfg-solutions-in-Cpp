//gfg pe bhi hai iska similar

//(x%k + k)%k is done to counter negative integers in the array-see fraz video after 10
//solution by pep-rem and k-rem ki freq same honi chahiye aur 0 remainder ki freq even honi chahiye
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size()&1) return false;
        unordered_map<int,int>m;
        for(auto x:arr) m[(x%k + k)%k]++;       //store the count of remainders in a map.
           for(int i=0;i<arr.size();i++)
        {
            int rem=(arr[i]%k + k)%k;
            if(rem==0)                         //if the remainder for an element is 0 then the count of numbers that give this remainder must be even.
            { 
                if(m[rem]%2!=0) return false;   //if count of numbers that give this remainder is odd all pairs can't be made hence return false.
            }         
            else if(m[rem] != m[k - rem]) return false;    //if the remainder rem and k-rem do not have the same count then pairs can not be made 
        }
        return true;
    }
};