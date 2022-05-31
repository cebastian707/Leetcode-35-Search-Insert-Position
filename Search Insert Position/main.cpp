/*By::Cebastian Santiago
* Leetcode 35
*/
#include<iostream>
#include<vector>
#include<set>

/*[1,3,5,6]
* 
*/
int searchInsert(std::vector<int>& nums, int target) {
	//if the target is less then the first 
	//number
	if (target < nums[0]) {
		return 0;
	}
	
	
	
	
	//variables
	std::set<int> Hash;
	int found = 0;
	

	//insert the elements into the hash
	for (size_t i = 0; i < nums.size(); i++) {
		Hash.insert(nums[i]);
	}

	//check if the target is in the set
	auto it = Hash.find(target);
	

	if (it ==Hash.end()){
		//then element is not in the vector
		int idx = target - 1;
		for (size_t i = 0; i < nums.size(); i++) {
			if (nums[i] == idx) {
				return i+1;
			}
		}


		idx = target + 1;
		for (size_t i = 0; i < nums.size(); i++) {
			if (nums[i] == idx) {
				return i;
			}
		}

	}


	else if(it != Hash.end()) {
		
		//else element in the vector
		for (size_t i = 0; i < nums.size(); i++) {
			//loop through vector till we find the match
			if (nums[i] == target) {
				return i;
			}
		}
	}
	return nums.size();

}



int main(int argc, char* argv[]) {
	std::vector<int> nums = { 2,3,4,8,10 };

	std::cout << searchInsert(nums, 0) << std::endl;

	return 0;
}