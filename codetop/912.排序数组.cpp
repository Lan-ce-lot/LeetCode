/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    // vector<int> tmp;
    // void mergeSort(vector<int>& nums, int l, int r) {
    //     if (l >= r) return ;
    //     int m = l + r >> 1;
    //     mergeSort(nums, l, m);
    //     mergeSort(nums, m + 1, r);
    //     int i = l, j = m + 1, cnt = 0;
    //     while (i <= m && j <= r) {
    //         if (nums[i] <= nums[j]) {
    //             tmp[cnt++] = nums[i++];
    //         } else {
    //             tmp[cnt++] = nums[j++];
    //         }
    //     }
    //      while (i <= m) {
    //         tmp[cnt++] = nums[i++];
    //     }
    //     while (j <= r) {
    //         tmp[cnt++] = nums[j++];
    //     }
    //     for (int i = 0; i < r - l + 1; ++i) {
    //         nums[i + l] = tmp[i];
    //     }
    // }
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; j++) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int p = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, p - 1);
            randomized_quicksort(nums, p + 1, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // tmp.resize((int)nums.size(), 0);
        // mergeSort(nums, 0, (int)nums.size() - 1);
        srand(unsigned(time(NULL)));
        randomized_quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end

