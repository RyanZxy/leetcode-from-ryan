/*更新时间：2021-04-13*/
/*1716.计算力扣银行的钱*/
/*个人题解*/
class Solution {
public:
    int totalMoney(int n) {
        int money = 0;
        int week = 1;               //week
        int day = 0;                //day in week
        for (int i = 0; i < n; i ++){
    
        day =i%7;              //day(1 less)  
        week=(i/7)+1;        //week

        money+=week+day;
        
        }
        return money;
    }
};

/*用时最少的方法与个人题解相同，不再重复列出*/

/*占用内存最少的题解*/
class Solution {
public:
    int totalMoney(int n) {
        int day=n%7,week=n/7;
        return ((day+1)*day)/2+day*week+(((week+7)*week)/2)*7;
    }
};

