class Solution {
public:
    
    static bool comparator(vector<int>& boxTypes1,vector<int>& boxTypes2){
        return boxTypes1[1]>boxTypes2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(),comparator);
      
        int capacity=0;
        int i=0;
        int maxval=0;
      
        while( i<boxTypes.size()){
              capacity+=boxTypes[i][0];
          
            if(capacity>truckSize){
                     capacity-=boxTypes[i][0];
                break;}
            maxval=maxval+(boxTypes[i][0]*boxTypes[i][1]);
            i++;
        
        }
        if(i==boxTypes.size())
        return maxval;
        else{
           int remainingval=truckSize-capacity;
         
                 maxval=maxval+(remainingval*boxTypes[i][1]);
             
            return maxval;
        }
    }
};