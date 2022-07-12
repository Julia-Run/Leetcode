/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end()); // words not visited;
        vector<vector<string>> res;
        if (!dict.count(endWord))
            return res;
        dict.erase(beginWord);
        dict.erase(endWord);

        unordered_map<string, int> layers{{beginWord, 0}};
        unordered_map<string, vector<string>> parents;

        queue<string> q;
        q.push(beginWord); // words I have visited;
        int layer = 0;
        bool found = false;
        while (!q.empty() && !found)
        {
            int len = q.size();
            while (len--) // current layer;
            {
                string s = q.front();
                q.pop();
                for (int i = 0; i < s.size(); ++i)
                {
                    // for every char in s -- have 26-1 times to replace;
                    string t = s;
                    for (int j = 0; j < 26; ++j)
                    {
                        char x = 'a' + j;
                        t[i] = x;
                        if (t == endWord)
                        {
                            found = true;
                            parents[t].emplace_back(s); // endWord is not in dict;
                        }
                        if (dict.count(t))
                        {
                            q.push(t);
                            dict.erase(t);
                            parents[t].emplace_back(s);
                            layers[t] = layers.at(s) + 1;
                        }
                        else if (layers.count(t) && layer + 1 == layers.at(t))
                        {
                            parents[t].emplace_back(s); // t can also teansform from t
                        }
                    }
                }
            }
            ++layer;
        }
        if (found) // dfs to output
        {
            vector<string> temp{endWord};
            dfs(endWord, beginWord, res, temp, parents);
        }
        return res;
    }

    void dfs(string curr, string s, vector<vector<string>> &res, vector<string> &temp, unordered_map<string, vector<string>> &parents)
    {
        if (curr == s)
        {
            res.emplace_back(vector<string>(temp.rbegin(), temp.rend()));
            return;
        }
        for (string x : parents[curr])
        {
            temp.emplace_back(x);
            dfs(x, s, res, temp, parents);
            temp.pop_back();
        }
    }
};
// @lc code=end
