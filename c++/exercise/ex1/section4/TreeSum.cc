#include<fstream>
#include<iostream>
#include<vector>
#include<ctime>
#include<functional>
#include<unistd.h>
#include<algorithm>
#include"/Users/mahaoyuan/Workpace/algorithm/c++/utils/stopwatch.h"

using namespace utils;



int TreeSum(const std::vector<int>& nums){
    int count = 0;
    for(int i = 0; i < nums.size(); i++)
        for(int j = i + 1 ; j < nums.size(); j++)
            for(int k = j + 1; k < nums.size(); k++){
                if (nums[i] + nums[j] + nums[k] == 0){
                    count++;
                    std::cout  << nums[i] << " " << nums[j] << " " <<nums[k] << std::endl;
                }
            }
    return count;
}

int BinarySearch(const std::vector<int>& nums, int target){
    if(nums.empty()){
        return -1;
    }
    int low = 0;
    int high = nums.size() - 1;
    int mid; 
    while(low <= high){
        mid = low + (high - low)/2;
        if(target < nums[mid]){
            high = mid - 1;
        }
        else if(target > nums[mid]){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}


int FastTreeSum(std::vector<int> nums){
    int cnt = 0;
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            if(BinarySearch(nums ,-(nums[i] + nums[j])) > j)
                cnt++;
        }
    }
    return cnt;
}


int main(int argc, char* argv[]){
    std::ifstream infile(argv[1]);
    std::vector<int> nums;
    int num;
    while(infile >> num){
        nums.push_back(num);
    }
    utils::Stopwatch time;
    //TreeSum test 
    std::cout << TreeSum(nums) << std::endl;
    std::cout << time.elapsedTime() << std::endl;

    utils::TimeTrial tt;
    double pre = tt.trial(75, TreeSum);
    for(int N = 125; N <= 25000; N+=N){
        double time = tt.trial(N, FastTreeSum);
        std::cout << N << " " << time << " " <<time/pre << std::endl;
        pre = time;
    }

    std::cout << "test binary search"  <<std::endl;
    std::vector<int> binary_nums;
    for(int i = 0 ; i < 10; i++){
        binary_nums.push_back(i);
    }
    std::cout << "result index:" << BinarySearch(binary_nums, 5) << std::endl;;
}