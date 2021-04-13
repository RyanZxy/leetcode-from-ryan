/*更新时间：2021-03-30*/
/*1046.最后一块石头的重量*/


/*个人题解*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1) return stones[0];
        priority_queue<int> tmp(stones.begin(),stones.end());
        while(tmp.size()>1)
        {
            int max=tmp.top();
            tmp.pop();
            int sec=tmp.top();
            tmp.pop();
            if(max==sec)
            {continue;}
            else
            {int res=max-sec;
            tmp.push(res);}
            
        }
        if(tmp.size()==0)
        {
            return 0;
        }
        else
        {
            return tmp.top();
        }
        
    }
};
