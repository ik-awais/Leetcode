#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> missing;
        int anchor = nums[0]; 
        for(int i=0; i < nums.size();)
        {
            if(anchor != nums[i])
            {
                missing.push_back(anchor++);
            }
            else
            {
                anchor = nums[i++]+1;
            }
        }
        return missing;
    }
};
int main(){
    Solution obj;
    vector<int> test = {1,2,4,5};
    vector<int> ans = obj.findMissingElements(test);
    for(int i:ans)cout << i << " ";
    return 0;
}