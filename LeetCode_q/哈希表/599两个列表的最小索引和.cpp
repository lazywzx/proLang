#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
假设 Andy 和 Doris 想在晚餐时选择一家餐厅，
并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 
如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。
*/

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    // 在相同的字符串中找到最小索引和的那一对，可能有多对
    unordered_map<string, size_t> list_map;
    vector<string> res;

    for (size_t i(0); i != list1.size(); ++ i) {
        list_map[list1[i]] = i;
    }

    size_t minsum(-1), curr_sum(0);
    for (size_t i(0); i != list2.size(); ++ i) {
        // 不需要尝试插入，直接find判断在不在即可
        if (list_map.find(list2[i]) != list_map.end()) {
            // 已存在，直接在这里尝试构建答案
            // 尝试答案，如果后续发现错误就重新开始
            curr_sum = i + list_map[list2[i]];
            if (curr_sum > minsum) {
                // 当前索引和已经比最小的大了，后面不可能出现结果了
                return res;
            }
            
            if (curr_sum == minsum) {
                // 如果现在就是多个答案的最小索引和
                res.emplace_back(list2[i]);
            }
            else if (curr_sum < minsum) {
                // 发现错误
                res.clear();
                res.emplace_back(list2[i]); // 当前的结果可能是最终答案，继续尝试
                minsum = curr_sum;
            }
        }
    }

    return res;
}
