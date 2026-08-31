class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> answer = {-1, -1};

        ListNode* previous = head;
        ListNode* current = head->next;

        int position = 1;
        int firstCritical = -1;
        int previousCritical = -1;
        int minimumDistance = INT_MAX;

        while (current->next != nullptr) {
            if ((current->val > previous->val &&
                 current->val > current->next->val) ||
                (current->val < previous->val &&
                 current->val < current->next->val)) {

                if (firstCritical == -1) {
                    firstCritical = position;
                }

                if (previousCritical != -1) {
                    minimumDistance = min(
                        minimumDistance,
                        position - previousCritical
                    );
                }

                previousCritical = position;
            }

            previous = current;
            current = current->next;
            position++;
        }

        if (firstCritical == -1 || firstCritical == previousCritical) {
            return answer;
        }

        int maximumDistance = previousCritical - firstCritical;

        return {minimumDistance, maximumDistance};
    }
};