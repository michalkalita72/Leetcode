#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum_b(vector<int>& nums, int target){
        vector<int> S;
        int nums_size = nums.size();
        for(int i = 0; i < nums_size; ++i){
            for(int j = 0; j < nums_size; j++){
                if( (nums[i] + nums[j] == target) && i != j){
                    S.push_back(i);
                    S.push_back(j);
                    return S;
                }
                else{
                    //do nothing
                }
            }
        }
        return S;
    }
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> S;
        int nums_size = nums.size();
        int i = 0; int j = nums_size - 1;
        while(i != j){
            if(nums[i] + nums[j] == target){
                S.push_back(i);
                S.push_back(j);
                return S;
            }
            else{
                if(i%2 ==0){
                    ++i;
                }
                else{
                    --j;
                }
            }
        }
        return S;
    }
};

int main(){
    int temp;
    Solution object;
    vector<int> nums = {3,3};
    int target = 6;
    vector<int> answer;
    answer = object.twoSum_b(nums, target);
    for(int i = 0; i < (int)answer.size(); ++i){
        std::cout << answer[i] << " ";
    }

    cin >> temp;
    return 0;
}