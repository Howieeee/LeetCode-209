class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int windowStart =0;
        int sum = 0;
        int length = numeric_limits<int>::max();//找最大的 int
        //cout << maxNum << endl;
        
        for(int windowEnd =0 ;windowEnd < nums.size();windowEnd++){
            sum += nums[windowEnd];  //+到 >= 目標 (擴展windowEnd)
            
            //cout << "sum " << sum << " ";
            while(sum>=target){ //可以縮小 左邊視窗
                //cout << "sum " << sum << " ";
                length = min( length , (windowEnd - windowStart + 1) ); //先取長度 再比大小
                sum -= nums[windowStart];
                windowStart +=1;
                //cout << "sum -- " << sum << " ";
                //cout << windowStart << " ";
            }
        }
        
        
        return (length==numeric_limits<int>::max()? 0:length);
    }       
    
};
