#include<vector>
#include<iostream>
int equalsNums(std::vector<int> nums){
    int cnt = 0;
    
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == nums[nums[i]]){
            cnt++;
        }
        else{
            nums[nums[i]] = nums[i];
        }
    }
    return cnt;
}

int main(){
    std::vector<int> nums = {1,3,5,6,6,7};
    std::cout << equalsNums(nums) << std::endl;
}