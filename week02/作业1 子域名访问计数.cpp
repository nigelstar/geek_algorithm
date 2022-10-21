class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        // 统计每个字符串中的域名访问次数
        for (const auto& cpdomain : cpdomains) {
            int index = 0;
            while (cpdomain[index] != ' ') {
                ++index;
            }
            int cnt = stoi(cpdomain.substr(0, index));

            buffer_[cpdomain.substr(index + 1, cpdomain.length() - index - 1)] += cnt;
            for (int i = index + 1; i < cpdomain.length(); ++i) {
                if (cpdomain[i] == '.') {
                    buffer_[cpdomain.substr(i + 1, cpdomain.length() - i - 1)] += cnt;
                }
            }
        }

        vector<string> ans{};
        for (const auto& it : buffer_) {
            ans.emplace_back(to_string(it.second) + " " + it.first);
        }
        return ans;
    }

private:
    unordered_map<string, int> buffer_;
};