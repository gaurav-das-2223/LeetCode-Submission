class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numbers;
        for( int i = 0; i < nums.size(); i++){
            int help = target - nums[i];
            if (numbers.find(help) != numbers.end()){
                return {numbers[help],i};
            }
            numbers[nums[i]] = i;
        }
        return {};
    }
};