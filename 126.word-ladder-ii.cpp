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
        // return min paths; BF; log edgeTo;
        unordered_set dict(wordList.begin(), wordList.end()); // repeated;
        vector<vector<string>> res;
        if (!dict.count(endWord))
            return res;
        dict.erase(beginWord);
        dict.erase(endWord);

        // find min path  fron s to end in dict;
        unordered_map<string, int> steps{{beginWord, 0}};
        unordered_map<string, vector<string>> edgeTo;
        queue<string> q;
        q.push(beginWord);
        bool found = false;
        int step = 0;
        while (!q.empty() && !found)
        {
            int len = q.size();
            while (len--)
            {
                string s = q.front();
                q.pop();
                // find where s leads to;
                string temp = s;
                for (int i = 0; i < temp.size(); ++i)
                {
                    for (int j = 0; j < 26; ++j)
                    {
                        char x = 'a' + j;
                        temp[i] = x; // change one char
                        if (temp == endWord)
                        {
                            found = true;              // found state change
                            edgeTo[temp].push_back(s); // necessary! endWord not in dict
                        }
                        if (dict.count(temp))
                        {
                            dict.erase(temp);
                            q.push(temp); // next layer
                            edgeTo[temp].push_back(s);
                            steps[temp] = steps.at(s) + 1;
                        }
                        else if (steps.count(temp) && step + 1 == steps.at(temp))
                        { // temp has been deleted from dict; but i can still go change to this word;
                            edgeTo[temp].push_back(s);
                        }
                    }
                    temp = s;
                }
            }
            ++step;
        }
        // found:
        if (found)
        {
            vector<string> curr{endWord};
            dfs(endWord, beginWord, curr, res, edgeTo);
        }
        return res;
    }

    void dfs(string word, string s, vector<string> &curr, vector<vector<string>> &res, unordered_map<string, vector<string>> &edgeTo)
    {
        if (word == s)
        {
            res.emplace_back(vector<string>(curr.rbegin(), curr.rend()));
            return;
        }
        for (string x : edgeTo[word])
        {
            curr.emplace_back(x);
            dfs(x, s, curr, res, edgeTo);
            curr.pop_back();
        }
    }
};
// @lc code=end
