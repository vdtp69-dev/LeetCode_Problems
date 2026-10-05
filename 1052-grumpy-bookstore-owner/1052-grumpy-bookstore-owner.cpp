class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n = customers.size();
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            if (grumpy[i] == 1)
                sum += customers[i];
        }
        long long maxSum = sum;
        for (int i = k; i < n; i++) {
            if (grumpy[i - k] == 1) {
                sum -= customers[i - k];
            }
            if (grumpy[i] == 1)
                sum += customers[i];
            if (maxSum < sum) {
                maxSum = sum;
            }
        }
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                maxSum += customers[i];
        }
        return maxSum;
    }
};