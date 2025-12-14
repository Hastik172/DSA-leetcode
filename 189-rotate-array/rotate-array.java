class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        int[] k_rotation = new int[nums.length];
        for(int i =0;i<nums.length;i++){
            k_rotation[(i+k)%nums.length] = nums[i];
        }
        for(int i=0;i<nums.length;i++){
            nums[i] = k_rotation[i];
        }

        
    }
}