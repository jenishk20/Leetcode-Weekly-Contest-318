class Solution {
public:
    long long maxi=1e17;
    
    long long  recur(vector<int>&factoryPos,int f,vector<int>&robot,int r,
                    vector<vector<long long>>&dp)
    {
         if(r==robot.size()) return 0;
        if(f==factoryPos.size()) return maxi;
       if(dp[r][f]!=-1) return dp[r][f];
        
       // cout<<f<<" "<<r<<endl;
        long long  op1=abs(factoryPos[f]-robot[r])+recur(factoryPos,f+1,robot,r+1,dp);
        long long  op2=recur(factoryPos,f+1,robot,r,dp);
        //cout<<op1<<" "<<op2<<endl;
        return dp[r][f]=min(op1,op2);
            
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        vector<int>factoryPos;
        sort(factory.begin(),factory.end());
        for(auto i:factory)
        {
            int idx=i[0];
            int times=i[1];
            while(times--)
                factoryPos.push_back(idx);
        }
       
        sort(factoryPos.begin(),factoryPos.end());
        sort(robot.begin(),robot.end());
        //cout<<robot.size()<<" "<<factoryPos.size()<<endl;
        vector<vector<long long>> dp(robot.size()+1,vector<long long>(factoryPos.size()+1,-1));
        return recur(factoryPos,0,robot,0,dp);
    }
};
