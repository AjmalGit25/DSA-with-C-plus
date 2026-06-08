#include <iostream>
#include <vector>
using namespace std;


void moveZeroes (vector<int>& nums) {
    int n = nums.size ();
    int insert_idx = 0;

    for (int i = 0; i < n; i++) {

        if (nums[i] == 0) {
            if (i + 1 < n && nums[i+1] != 0){

                nums[insert_idx] = nums[i+1];
                nums[i+1] = 0;
                insert_idx++;
            }
        } else {
            insert_idx++;
        }
    }
}

//void moveZeroes (vector<int>& nums) {
//
//	int i = 0;
//	int n = nums.size();
//	while (i < n) {
//		if (nums[i] == 0) {
//			nums.erase(nums.begin() + i);
//			nums.push_back(0);
//			n--;
//		} else {
//			i++;
//		}
//	}
//}
void show_elements (vector<int>& nums) {
	for (int x : nums) {
		cout << x << " ";
	}
}

int main() {
	vector<int> nums = {1,0,8,9};

	show_elements (nums);

	cout << endl;


	moveZeroes (nums);

	show_elements (nums);

	return 0;
}