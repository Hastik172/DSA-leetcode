class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& candidates, int target, int start) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return res;
    }
};