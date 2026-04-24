class Solution {
public:
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];

        int pivot = nums[l + rand() % (r - l + 1)];

        int i = l, lt = l, gt = r;

        // 3-way partition
        while (i <= gt) {
            if (nums[i] < pivot)
                swap(nums[i++], nums[lt++]);
            else if (nums[i] > pivot)
                swap(nums[i], nums[gt--]);
            else
                i++;
        }

        // Now:
        // nums[l ... lt-1] < pivot
        // nums[lt ... gt] == pivot
        // nums[gt+1 ... r] > pivot

        if (k < lt)
            return quickSelect(nums, l, lt - 1, k);
        else if (k > gt)
            return quickSelect(nums, gt + 1, r, k);
        else
            return nums[k]; // inside equal region
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};