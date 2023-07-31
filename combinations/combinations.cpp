class Solution {
public:
    
    void combination(int n, int k, int start, int &limit, vector<int>temp,vector<vector<int>>&result)
    {
        // base case k==0 we insert temp result in to result vector
        // as we have already got one combination containg k elements
        if(k==0)
        {
            result.push_back(temp);
            return;
        }
        
        // base case n==0, no combination possible and so return
        if(n==0)return;
        
        // loop through start to limit-k+1 => limit = N (given total items)
        for(int i=start;i<=limit-k+1;i++)
        {
            // add current item for case 1: consider current item
            temp.push_back(i);
            
            // call combination(n-1,r-1)
            combination(n-1,k-1,i+1,limit,temp,result);
            
            // remove current item for case 2: ignore current item
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
           
        // result vector 
        vector<vector<int>>result;
        
        // dummy vector for holding progressing results
        vector<int>temp;
        
        // recursion call with start value 1
        combination(n,k,1,n,temp,result);   
        
        return result;
            
    }
};