class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        priority_queue<int, vector<int>> pq;

        for (int x : nums) {
            pq.push(x);
        }

        int answer = 1;
        int count = 1;

        int previous = pq.top();
        pq.pop();

        while (!pq.empty()) {
            int current = pq.top();
            pq.pop();

            if (current == previous) {
                continue;
            }

            if (current == previous - 1) {
                count++;
            }
            else {
                count = 1;
            }

            answer = max(answer, count);
            previous = current;
        }

        return answer;
    }
};