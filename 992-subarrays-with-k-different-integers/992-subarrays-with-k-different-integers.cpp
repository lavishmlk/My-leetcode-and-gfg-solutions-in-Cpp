//interviewbit pe kiya pehle ye same question code with alina ka dekha
//iske pichla solution khud ia tha maine par usme tle aa gya
class Solution {
public:
    
    int atmost(vector<int> &arr, int B){
int n=arr.size();
unordered_map<int,int>m;

int i=0;
int j=0;
int Count=0;
while(i<n){
    m[arr[i]]++;
    while(m.size()>B){
   
        m[arr[j]]--;
        if(m[arr[j]]==0){
        m.erase(arr[j]);}
        j++;
                     }
Count=Count+(i-j+1);
i++;
}
return Count;
}
    
    int subarraysWithKDistinct(vector<int>& arr, int B) {
        int ans=atmost(arr,B)-atmost(arr,B-1);
        return ans;
    }
};