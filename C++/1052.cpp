/*更新时间：2021-03-30*/
/*1052.生气的书店老板*/
/*个人题解*/
/*执行用时44ms，内存10.9MB*/

#include<numeric>
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int countMax=0;//记录满意的最大总时间
        // vector<int> netT(customers);
        // for(int i=0;i<customers.size();i++){
        //     netT[i]=customers[i]*grumpy[i];
        // }
        for(int i=0;i<X;i++){
             countMax+=customers[i];
        }
        for(int i=X;i<customers.size();i++){
            countMax+=customers[i]*(1-grumpy[i]);
        }
        // cout<<"init max"<<countMax<<endl;
        //计算得到初始的最大时间
        //排查得出下面的循环体出现了heap-buffer-flow,重新修改循环条件如下
        int temp=countMax;
        for(int i=0;i<customers.size()-X;i++){
            temp=temp-customers[i]+customers[i]*(1-grumpy[i])-customers[X+i]*(1-grumpy[X+i])+customers[X+i];
            // cout<<temp<<endl;
            if(temp>=countMax){
                countMax=temp;
                // cout<<"max"<<countMax<<endl;
            }
        }
        
        return countMax;
        
    }
};


/*耗时最少的提交记录*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sz = customers.size();
        int right = 0;
        int left = 0;
        int result = 0;
        int winSum = 0;
        int maxWinSum = 0;
        while(right < sz){
            if(right < X){
                if(grumpy[right] == 0){
                    result += customers[right];
                } else {
                    winSum += customers[right];
                }
            } else {
                result += customers[right] * (grumpy[right] ^ 1);
                winSum = winSum - customers[left] * grumpy[left]
                   + customers[right] * grumpy[right];
                   left++;
            }
            maxWinSum = max(maxWinSum, winSum);
            right++;
        }
        return result + maxWinSum;
    }
};

/*占用内存最少的提交记录*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n=customers.size(),ans=0,maxl=0,tl=0,i=0;
        for(;i<n;++i){
            if(grumpy[i])grumpy[i]=customers[i];
            else ans+=customers[i];
        }
        for(i=0;i<k;++i){
            maxl+=grumpy[i];
            tl+=grumpy[i];
        }
        for(;i<n;++i){
            tl+=grumpy[i]-grumpy[i-k];
            maxl=max(maxl,tl);
        }
        return ans+maxl;
    }
}; 

