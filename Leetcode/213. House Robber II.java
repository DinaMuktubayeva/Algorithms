// The main point is that you can't rob both the first and the last houses.

// Therefore, the core idea is to apply DP twice: when you rob the first house, and when you don't (you rob the last one).

// The DP algorithm:
// 1. Iterate over houses
// 2. At ith house you have 2 options:
//      a. Keep the money from the (i-1)th (previous) house, skipping the ith house
//      b. Rob the ith house after the (i-2)th house, skipping the (i-1)th
// 3. Choose the most profitable option (obviously)
// 4. Return the sum you've got after last house

// This solution runs in O(n) because we make two passes over an array that is one item smaller than the input array.
// O(n) extra space is required to store the amount of money after each house

class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1)
            return nums[0];
        if (nums.length == 2)
            return Math.max(nums[0], nums[1]);

        // 1st option: including the 1st and excluding the last house
        int resultWithFirst = solve(nums, 0, nums.length - 2);
        // 2nd option: excluding the 1st and including the last house
        int resultWithLast = solve(nums, 1, nums.length - 1);

        // Return the maximum of the two results
        return Math.max(resultWithFirst, resultWithLast);
    }

    public int solve(int[] nums, int start, int end) {
        if (start == end)
            return nums[start];

        // Array to store the maximum sum at the current iteration
        // while traversing all houses
        int money[] = new int[nums.length];

        /* Base cases */
        money[start] = nums[start];

        // At the 2nd house, we decide to rob
        // either the 1st house or the 2nd
        // This is the core idea of the transition function
        money[start + 1] = Math.max(nums[start + 1], nums[start]);

        for (int i = start + 2; i <= end; ++i)
            /*
             * At ith house we have two options: 1. not rob it, keeping the money from the
             * (i-1)th house 2. rob it after the (i-2)th house, skipping the (i-1)th house
             * We choose the one that gives the max amount
             */
            money[i] = Math.max(money[i - 1], money[i - 2] + nums[i]);

        // Return the sum that we have at the last house
        return money[end];
    }
}