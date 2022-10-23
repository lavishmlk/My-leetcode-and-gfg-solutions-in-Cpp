class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
     int Xor = 0;
    for(int i = 0; i < nums.size(); i++) {
        Xor ^= nums[i] ^ (i + 1);
    }
    int diffBit = Xor & (~(Xor - 1)), a = 0;
    for(int i = 0; i < nums.size(); i++) {
        if((diffBit & nums[i]) != 0) {
      cout<<diffBit;
            a ^= nums[i];
        }
        if((diffBit & (i + 1)) != 0) {
            a ^= (i + 1);
        }
    }
    for(int num: nums) {
        if(num == a) {
            return {a, Xor ^ a};
        }
    }
    return {Xor ^ a, a};
    }
};