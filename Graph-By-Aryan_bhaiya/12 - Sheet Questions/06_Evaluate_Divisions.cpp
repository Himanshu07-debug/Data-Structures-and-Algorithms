#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1;
const long long NINF = LLONG_MIN;

// Graph Intuition came like this ----> for a / c in first T.C --> (a/b) * (b/c) 
//                                      If dest i.e c do not exist at last in the traversal --> ans[i] = -1

// CONCEPT --> In Math, Division can be occured in Chain

// REMEMBER ---------->>
// In this Question, there is no need to worry about ["b" , "c"] , ["b" , "d"] and [ "bc" , "de" ] 
// Becz it is clearly mention in Question, all strings are separate variables , therefore "b" , "d" , "bc" are different.
// Tension mat lo ki query me aaye to cancel out dekhke solve ho sakte hai yaa "bc" ko split krna honga ---> NO 



vector<double> calcEquation(vector<vector<string>> &eq, vector<double> &val, vector<vector<string>> &qrr)
{

    unordered_map<string, vector<pair<string, double>>> gr;

    for (int i = 0; i < eq.size(); i++)
    {
        gr[eq[i][0]].push_back({eq[i][1], val[i]});

        double x = 1.0 / val[i];
        gr[eq[i][1]].push_back({eq[i][0], x});
    }

    vector<double> ans(qrr.size(), 0.0);

    for (int i = 0; i < qrr.size(); i++)
    {

        string a = qrr[i][0], b = qrr[i][1];

        if (gr[a].size() == 0 || gr[b].size() == 0)
            ans[i] = -1.0;
        else
        {

            queue<pair<string, double>> q;

            unordered_set<string> vis;
            vis.insert(a);

            q.push({a, 1.0});

            ans[i] = -1.0;

            while (!q.empty())
            {

                string s = q.front().first;
                double v = q.front().second;
                q.pop();

                if (s == b)
                {
                    ans[i] = v;
                    break;
                }

                for (auto [x, y] : gr[s])
                {

                    // cout << x << "--";

                    if (!vis.count(x))
                    {
                        q.push({x, v * y});
                        vis.insert(x);
                    }
                }
                // cout << endl;
            }
        }
    }

    return ans;
}
