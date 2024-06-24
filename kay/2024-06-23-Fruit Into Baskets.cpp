#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int maxNum = 1;
        int right = left + 1;
        int curNum = 1;
        unordered_map<int, int> basketTypeForMap;
        basketTypeForMap[fruits[left]]++;
        while (right < fruits.size()) {
            basketTypeForMap[fruits[right]]++;
            while (basketTypeForMap.size() > 2) {
                basketTypeForMap[fruits[left]]--;
                if (basketTypeForMap[fruits[left]] == 0)
                    basketTypeForMap.erase(fruits[left]);
                left += 1;
            }
            maxNum = max(maxNum, right - left + 1);
            right += 1;
        }
        return maxNum;
    }
};

/*
Problem Understanding and Approach
English:
The problem is to find the longest subarray containing at most two distinct types of fruits. We need to efficiently keep track of the fruit types in the current subarray and their counts.

Korean:
�� ������ �ִ� �� ������ ������ �����ϴ� ���� �� �����̸� ã�� ���Դϴ�. ���� �������� ���� ������ �� ������ ȿ�������� �����ؾ� �մϴ�.

Data Structures Used
English:

unordered_map<int, int> fruitCount: To count the occurrences of each fruit type in the current subarray.
int left: To keep track of the left boundary of the sliding window.
int maxNum: To store the maximum length of the subarray with at most two distinct fruit types.
int right: To iterate through the array.
int curNum: To keep track of the current number of fruits in the window (not needed after refactoring).
Korean:

unordered_map<int, int> fruitCount: ���� �������� �� ���� ������ �߻� �󵵸� ����ϱ� ���� ����մϴ�.
int left: �����̵� �������� ���� ��踦 �����ϱ� ���� ����մϴ�.
int maxNum: �ִ� �� ������ ������ �����ϴ� �������� �ִ� ���̸� �����ϱ� ���� ����մϴ�.
int right: �迭�� ��ȸ�ϱ� ���� ����մϴ�.
int curNum: ������ ���� ���� ���� ������ �����ϱ� ���� ����մϴ� (�����丵 �� ���ʿ���).
Algorithm Steps
English:

Initialize variables left, maxNum, and fruitCount.
Traverse the array with the right pointer.
For each element at right, add it to the hash map and update the count.
If the window contains more than two types of fruits, adjust the window by removing the leftmost fruit and moving the left pointer.
Update maxNum with the current window size if it's larger.
Return maxNum after traversing the array.
Korean:

���� left, maxNum, fruitCount�� �ʱ�ȭ�մϴ�.
right �����ͷ� �迭�� ��ȸ�մϴ�.
right�� �ִ� �� ��Ҹ� �ؽ� �ʿ� �߰��ϰ� ������ ������Ʈ�մϴ�.
�����찡 �� ���� �̻��� ������ �����ϸ�, ���� ���� ������ �����ϰ� left �����͸� �̵����� �����츦 �����մϴ�.
���� ������ ũ�Ⱑ �� ũ�� maxNum�� ������Ʈ�մϴ�.
�迭�� �� ��ȸ�� �� maxNum�� ��ȯ�մϴ�.
Code Explanation Line by Line
Code:

cpp
�ڵ� ����
class FruitBasket {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0; // Initialize the left pointer of the sliding window
        int maxNum = 1; // Initialize maxNum to store the maximum length of the subarray with at most two distinct fruit types
        int right = 0; // Initialize the right pointer of the sliding window
        unordered_map<int, int> fruitCount; // Initialize a hash map to count occurrences of each fruit type in the current subarray

        while (right < fruits.size()) { // Traverse the array with the right pointer
            fruitCount[fruits[right]]++; // Increment the count of the current fruit in the hash map

            while (fruitCount.size() > 2) { // If the window contains more than two types of fruits
                fruitCount[fruits[left]]--; // Decrement the count of the leftmost fruit
                if (fruitCount[fruits[left]] == 0) { // If the count becomes zero, remove it from the hash map
                    fruitCount.erase(fruits[left]);
                }
                left++; // Move the left pointer to the right
            }

            maxNum = max(maxNum, right - left + 1); // Update maxNum with the current window size if it's larger
            right++; // Move the right pointer to the right
        }

        return maxNum; // Return the maximum length of the subarray with at most two distinct fruit types
    }
};
Line-by-line Explanation:

class FruitBasket {

English: Define the FruitBasket class.
Korean: FruitBasket Ŭ������ �����մϴ�.
public:

English: Define the public access specifier.
Korean: public ���� �����ڸ� �����մϴ�.
int totalFruit(vector<int>& fruits) {

English: Define the totalFruit function that takes a vector of integers representing fruit types and returns an integer.
Korean: ���� ������ ��Ÿ���� ���� ���͸� �Է����� �޾� ������ ��ȯ�ϴ� totalFruit �Լ��� �����մϴ�.
int left = 0;

English: Initialize the left pointer of the sliding window.
Korean: �����̵� �������� ���� �����͸� �ʱ�ȭ�մϴ�.
int maxNum = 1;

English: Initialize maxNum to store the maximum length of the subarray with at most two distinct fruit types.
Korean: �ִ� �� ������ ������ �����ϴ� �������� �ִ� ���̸� �����ϱ� ���� maxNum�� �ʱ�ȭ�մϴ�.
int right = 0;

English: Initialize the right pointer of the sliding window.
Korean: �����̵� �������� ������ �����͸� �ʱ�ȭ�մϴ�.
unordered_map<int, int> fruitCount;

English: Initialize a hash map to count occurrences of each fruit type in the current subarray.
Korean: ���� �������� �� ���� ������ �߻� �󵵸� ����ϱ� ���� �ؽ� ���� �ʱ�ȭ�մϴ�.
while (right < fruits.size()) {

English: Traverse the array with the right pointer.
Korean: right �����ͷ� �迭�� ��ȸ�մϴ�.
fruitCount[fruits[right]]++;

English: Increment the count of the current fruit in the hash map.
Korean: �ؽ� �ʿ��� ���� ������ ������ ������ŵ�ϴ�.
while (fruitCount.size() > 2) {

English: If the window contains more than two types of fruits.
Korean: �����찡 �� ���� �̻��� ������ �����ϸ�.
fruitCount[fruits[left]]--;

English: Decrement the count of the leftmost fruit.
Korean: ���� ���� ������ ������ ���ҽ�ŵ�ϴ�.
if (fruitCount[fruits[left]] == 0) {

English: If the count becomes zero, remove it from the hash map.
Korean: ������ 0�� �Ǹ� �ؽ� �ʿ��� �����մϴ�.
fruitCount.erase(fruits[left]);

English: Remove the element from the hash map.
Korean: ��Ҹ� �ؽ� �ʿ��� �����մϴ�.
left++;

English: Move the left pointer to the right.
Korean: ���� �����͸� ���������� �̵���ŵ�ϴ�.
}

English: Close the while (fruitCount.size() > 2) block.
Korean: while (fruitCount.size() > 2) ����� �ݽ��ϴ�.
maxNum = max(maxNum, right - left + 1);

English: Update maxNum with the current window size if it's larger.
Korean: ���� ������ ũ�Ⱑ �� ũ�� maxNum�� ������Ʈ�մϴ�.
right++;

English: Move the right pointer to the right.
Korean: ������ �����͸� ���������� �̵���ŵ�ϴ�.
}

English: Close the while (right < fruits.size()) block.
Korean: while (right < fruits.size()) ����� �ݽ��ϴ�.
return maxNum;

English: Return the maximum length of the subarray with at most two distinct fruit types.
Korean: �ִ� �� ������ ������ �����ϴ� �������� �ִ� ���̸� ��ȯ�մϴ�.
}

English: Close the totalFruit function.
Korean: totalFruit �Լ��� �ݽ��ϴ�.
};

English: Close the FruitBasket class.
Korean: FruitBasket Ŭ������ �ݽ��ϴ�.
Complexity Analysis
Time Complexity (T(c)):

English:
The time complexity is O(N) because each element is processed at most twice - once by the right pointer and at most once by the left pointer.

Korean:
�ð� ���⵵�� O(N)�Դϴ�. �� ��Ҵ� ������ �����Ϳ� ���� �� ��, ���� �����Ϳ� ���� �ִ� �� �� ó���Ǳ� �����Դϴ�.

Space Complexity (S(c)):

English:
The space complexity is O(1) because the hash map will contain at most 3 keys at any given time (since there are only 2 types of fruits allowed and the extra one is for the condition check).

Korean:
���� ���⵵�� O(1)�Դϴ�. �ؽ� ���� �ִ� 3���� Ű�� ������ �� �ֱ� �����Դϴ� (�ִ� 2������ ���ϸ� ���ǰ�, ���� Ȯ���� ���� �߰��� �ϳ��Դϴ�).*/