/*更新时间 2021-04-22*/
/*0004。两个有序数组的中位数*/
/*个人题解1*/
/*  该题解为刚接触leetcode时提交，近日看到有人发帖讨论此题，发现可以使用二分查找予以优化。
    因此本题会有两份个人题解*/

class Solution {//该题解思路为比较简单的先合并，再从新的vector得到中位数
public:
    vector<int> fullNums;    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        //    两容器大小
        
        int indm=0;
        int indn=0;
        int ind=0;
        //    排序下标
        
        double res;
        //    返回值
        
        while(ind<m+n && indm<nums1.size() && indn<nums2.size()){
            
            if(nums1[indm]<=nums2[indn]){
                fullNums.push_back(nums1[indm]);
                indm++;
                cout<<fullNums[ind]<<endl;
            }
            else{
                fullNums.push_back(nums2[indn]);
                indn++;
                cout<<fullNums[ind]<<endl;
            }
            
            ind++;
        }
        
        
        if(indm<nums1.size()){
            while(indm<nums1.size()){
                fullNums.push_back(nums1[indm]);
                indm++;
                cout<<fullNums[ind]<<endl;
                ind++;
            }
        }
        else if(indn<nums2.size()){
             while(indn<nums2.size()){
                fullNums.push_back(nums2[indn]);
                indn++;
                cout<<fullNums[ind]<<endl;
                 ind++;
            }
        }
        else{
            ;
        }       
        //    两容器重构造,fullNum已经排序
        
        if(fullNums.size()&1){//   &1=1为奇数
            res=(double)fullNums[((fullNums.size()+1)/2)-1];
            cout<<(double)fullNums[((fullNums.size()+1)/2)-1];
        }
        else{
            res=(double)((fullNums[(((fullNums.size())/2))]+fullNums[(((fullNums.size())/2)-1)])/2.0);
            cout<<fullNums[(((fullNums.size())/2))]<<"+"<<fullNums[(((fullNums.size())/2)-1)];
        }
        
//         int maxa=Math.max(nums1[m-1],nums2[n-2]);
// 		//    找到最大值
		
// 		int temp[]=new int[++maxa];
// 		for(int i=0;i<fullNums.size();i++){
// 			temp[fullNums[i]]++;
// 		}//   传入的数字，对应下标值相等的temp[]加1
		
//         if(fullNums.size()/2==0){
//             return (double)(temp[fullNums.size()/2-2]+[fullNums.size()/2-1])/2.0;
//         }
//         else{
//             return (double)(temp[fullNums.size()/2-1]);
//         }
        return res;
    }
};