class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) { // O(N)
        long long maxSum = 0;
        long long curSum = 0;
        int left = 0, right = 0;
        unordered_map<int, int> elementCount;
        while (right < k && right < nums.size()) {
            elementCount[nums[right]]++;
            curSum += nums[right++];
        }
        if (elementCount.size() == k)
            maxSum = curSum;
        while (right < nums.size()) {
            elementCount[nums[left]]--;
            if (elementCount[nums[left]] == 0)
                elementCount.erase(nums[left]);
            elementCount[nums[right]]++;
            curSum = curSum - nums[left] + nums[right];
            if (elementCount.size() == k)
                maxSum = max(maxSum, curSum);
            left++;
            right++;
        }
        return maxSum;
    }
};
/*


Problem Understanding and Approach
English:
The problem is to find the maximum sum of a subarray of length k where all elements in the subarray are unique. This requires us to efficiently keep track of the elements in the current subarray, their counts, and the sum of the subarray.

Korean:
�� ������ ���̰� k�� �������� �� �߿��� ��� ��Ұ� ������ ����� �ִ� ���� ã�� ���Դϴ�. �̸� ���� ���� �������� ���, �׵��� ����, �������� ���� ȿ�������� �����ؾ� �մϴ�.

English:
To solve this problem, we can use a sliding window approach combined with a hash map. The sliding window will help in maintaining a subarray of size k, and the hash map will keep track of the count of each element within the window.

Korean:
�� ������ �ذ��ϱ� ���� �����̵� ������ ���ٹ��� �ؽ� ���� �����Ͽ� ����� �� �ֽ��ϴ�. �����̵� ������� ���̰� k�� �����̸� �����ϴ� �� ������ �Ǹ�, �ؽ� ���� ������ �� �� ����� ������ �����ϴ� �� ���˴ϴ�.

Data Structures Used
English:

unordered_map<int, int> elementCount: To count the occurrences of elements in the current subarray.
long long currentSum: To keep track of the sum of the current subarray.
long long maxSum: To store the maximum sum of a subarray with unique elements of size k.
Korean:

unordered_map<int, int> elementCount: ���� �������� ��� �߻� �󵵸� ����ϱ� ���� ����մϴ�.
long long currentSum: ���� �������� ���� �����ϱ� ���� ����մϴ�.
long long maxSum: ���̰� k�� ������ ��Ҹ� ���� �������� �ִ� ���� �����ϱ� ���� ����մϴ�.
Algorithm Steps
English:

Initialize variables maxSum, currentSum, and left.
Traverse the array with a right pointer.
For each element at right, add it to the hash map and update the current sum.
If the window size exceeds k, adjust the window by removing the leftmost element and moving the left pointer.
If the window size is k and all elements are unique, update maxSum.
Return maxSum after traversing the array.
Korean:

���� maxSum, currentSum, left�� �ʱ�ȭ�մϴ�.
right �����ͷ� �迭�� ��ȸ�մϴ�.
right�� �ִ� �� ��Ҹ� �ؽ� �ʿ� �߰��ϰ� ���� ���� ������Ʈ�մϴ�.
������ ũ�Ⱑ k�� �ʰ��ϸ�, ���� ���� ��Ҹ� �����ϰ� left �����͸� �̵����� �����츦 �����մϴ�.
������ ũ�Ⱑ k�̰� ��� ��Ұ� ������ ��� maxSum�� ������Ʈ�մϴ�.
�迭�� �� ��ȸ�� �� maxSum�� ��ȯ�մϴ�.


Code Explanation Line by Line

Code:

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0; // Initialize maxSum to store the maximum sum of a subarray with unique elements of size k
        long long currentSum = 0; // Initialize currentSum to keep track of the current subarray's sum
        int left = 0; // Initialize the left pointer of the sliding window
        unordered_map<int, int> elementCount; // Initialize a hash map to count occurrences of elements in the current subarray

        for (int right = 0; right < nums.size(); ++right) { // Traverse the array with the right pointer
            elementCount[nums[right]]++; // Increment the count of the current element in the hash map
            currentSum += nums[right]; // Add the current element to the current sum

            if (right - left + 1 > k) { // If the window size exceeds k
                elementCount[nums[left]]--; // Decrement the count of the leftmost element
                if (elementCount[nums[left]] == 0) { // If the count becomes zero, remove it from the hash map
                    elementCount.erase(nums[left]);
                }
                currentSum -= nums[left]; // Subtract the leftmost element from the current sum
                left++; // Move the left pointer to the right
            }

            if (right - left + 1 == k && elementCount.size() == k) { // If the window size is k and all elements are unique
                maxSum = max(maxSum, currentSum); // Update maxSum with the current sum if it is larger
            }
        }

        return maxSum; // Return the maximum sum of a subarray with unique elements of size k
    }
};


Line-by-line Explanation:

class Solution {

English: Define the Solution class.
Korean: Solution Ŭ������ �����մϴ�.
public:

English: Define the public access specifier.
Korean: public ���� �����ڸ� �����մϴ�.
long long maximumSubarraySum(vector<int>& nums, int k) {

English: Define the maximumSubarraySum function that takes a vector of integers and an integer k as input and returns a long long integer.
Korean: ���� ���Ϳ� ���� k�� �Է����� �޾� long long ������ ��ȯ�ϴ� maximumSubarraySum �Լ��� �����մϴ�.
long long maxSum = 0;

English: Initialize maxSum to store the maximum sum of a subarray with unique elements of size k.
Korean: ���̰� k�� ������ ��Ҹ� ���� �������� �ִ� ���� �����ϱ� ���� maxSum�� �ʱ�ȭ�մϴ�.
long long currentSum = 0;

English: Initialize currentSum to keep track of the current subarray's sum.
Korean: ���� �������� ���� �����ϱ� ���� currentSum�� �ʱ�ȭ�մϴ�.
int left = 0;

English: Initialize the left pointer of the sliding window.
Korean: �����̵� �������� ���� �����͸� �ʱ�ȭ�մϴ�.
unordered_map<int, int> elementCount;

English: Initialize a hash map to count occurrences of elements in the current subarray.
Korean: ���� �������� ��� �߻� �󵵸� ����ϱ� ���� �ؽ� ���� �ʱ�ȭ�մϴ�.
for (int right = 0; right < nums.size(); ++right) {

English: Traverse the array with the right pointer.
Korean: right �����ͷ� �迭�� ��ȸ�մϴ�.
elementCount[nums[right]]++;

English: Increment the count of the current element in the hash map.
Korean: �ؽ� �ʿ��� ���� ����� ������ ������ŵ�ϴ�.
currentSum += nums[right];

English: Add the current element to the current sum.
Korean: ���� ��Ҹ� ���� �տ� ���մϴ�.
if (right - left + 1 > k) {

English: If the window size exceeds k.
Korean: ������ ũ�Ⱑ k�� �ʰ��ϸ�.
elementCount[nums[left]]--;

English: Decrement the count of the leftmost element.
Korean: ���� ���� ����� ������ ���ҽ�ŵ�ϴ�.
if (elementCount[nums[left]] == 0) {

English: If the count becomes zero, remove it from the hash map.
Korean: ������ 0�� �Ǹ� �ؽ� �ʿ��� �����մϴ�.
elementCount.erase(nums[left]);

English: Remove the element from the hash map.
Korean: ��Ҹ� �ؽ� �ʿ��� �����մϴ�.
currentSum -= nums[left];

English: Subtract the leftmost element from the current sum.
Korean: ���� �տ��� ���� ���� ��Ҹ� ���ϴ�.
left++;

English: Move the left pointer to the right.
Korean: ���� �����͸� ���������� �̵���ŵ�ϴ�.
if (right - left + 1 == k && elementCount.size() == k) {

English: If the window size is k and all elements are unique.
Korean: ������ ũ�Ⱑ k�̰� ��� ��Ұ� ������ ���.
maxSum = max(maxSum, currentSum);

English: Update maxSum with the current sum if it is larger.
Korean: ���� ���� �� ũ�� maxSum�� ������Ʈ�մϴ�.
}

English: Close the if and for blocks.
Korean: if�� for ����� �ݽ��ϴ�.
return maxSum;

English: Return the maximum sum of a subarray with unique elements of size k.
Korean: ���̰� k�� ������ ��Ҹ� ���� �������� �ִ� ���� ��ȯ�մϴ�.
}

English: Close the maximumSubarraySum function.
Korean: maximumSubarraySum �Լ��� �ݽ��ϴ�.
};

English: Close the Solution class.
Korean: Solution Ŭ������ �ݽ��ϴ�.
*/