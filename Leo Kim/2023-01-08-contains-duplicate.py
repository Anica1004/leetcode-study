class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:

        seen = set()

        for i in nums:   ## O(n)
            if i in seen: ## O(1)
                return True
            else:
                seen.add(i)

        return False