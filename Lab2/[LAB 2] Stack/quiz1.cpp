#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int baseballScore(string ops)
{
    /*TODO*/
    vector<int> scores;

    for (char op : ops)
    {
        if (isdigit(op))
            scores.push_back(op - '0');
        else if (op == 'C')
        {
            if (!scores.empty())
                scores.pop_back();
        }
        else if (op == 'D')
        {
            if (!scores.empty())
                scores.push_back(scores.back() * 2);
        }
        else if (op == '+')
        {
            if (scores.size() >= 2)
            {
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
            }
        }
    }

    int total = 0;
    for (int score : scores)
    {
        total += score;
    }
    return total;
}