/*更新时间：2021-03-29*/



/*耗时最少的提交记录*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int len = nums.size();
        for (int i =0; i<len-1; i++)
        {
            for (int j=i+1;j<len;j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
   
};

/*占用内存最少的提交记录*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};


/*个人题解*/
/*执行用时28ms，内存10.1MB*/

class Solution {
public:
      vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        unordered_map<int, int> hashmap;
	for (int i = 0; i < nums.size(); i++)
	{
		if (hashmap.count(nums[i]))  //check if this num is already in map
			continue;
		hashmap[nums[i]] = i;
	}
	int find;  //find is the expected number for add-up to target
	for (int i = 0; i < nums.size(); i++)  //mark：！第二次依旧是以数组为基准遍历
	{
		find = target - nums[i];
		auto iter = hashmap.find(find);
		if (iter != hashmap.end() && iter->second != i)  //the item exist and not 'i'-self
		{
            if(i<iter->second){
            temp.push_back(i);
            temp.push_back(iter->second);
			break;
            }
            else{
                temp.push_back(iter->second);
                temp.push_back(i);
                break;
            }
		}
	}
    return temp;
    }
};

//悄悄：这题两年前做的啊哈哈哈看了看自己两年前写的代码简直毫无美观可言哈哈哈哈嗝