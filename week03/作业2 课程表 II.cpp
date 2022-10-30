class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        to_.resize(numCourses);
        inDegree_.resize(numCourses);

        for (const auto& requisite : prerequisites) {
            to_[requisite.back()].push_back(requisite.front());
            ++inDegree_[requisite.front()];
        }

        vector<int> ans{};
        ans.reserve(numCourses);
        queue<int> queue{};
        for (int course = 0; course < numCourses; ++course) {
            if (inDegree_[course] == 0) {
                queue.push(course);
            }
        }

        while (!queue.empty()) {
            ans.push_back(queue.front());
            queue.pop();
            for (auto course : to_[ans.back()]) {
                --inDegree_[course];
                if (inDegree_[course] == 0) {
                    queue.push(course);
                }
            }
        }

        if (ans.size() == numCourses) {
            return ans;
        }

        return {};
    }

private:
    vector<vector<int>> to_;
    vector<int> inDegree_;
};