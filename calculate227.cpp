#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// int calculate(string s)
// {
//     stack<int> num;
//     stack<char> ch;
//     int res = 0;
//     for (auto &c : s)
//     {
//         if (c == ' ')
//         {
//             continue;
//         }
//         if (c >= '0' && c <= '9')
//         {
//             if (ch.empty())
//             {
//                 num.push(c - '0');
//             }
//             else
//             {
//                 char t = ch.top();
//                 if (t == '*' || t == '/')
//                 {
//                     int second = c - '0';
//                     int first = num.top();
//                     num.pop();
//                     if (t == '*')
//                     {
//                         num.emplace(first * second);
//                     }
//                     else
//                     {
//                         num.emplace(first / second);
//                     }
//                     ch.pop();
//                 }
//                 else
//                 {
//                     num.emplace(c - '0');
//                 }
//             }
//         }
//         else
//         {
//             ch.emplace(c);
//         }
//     }
//     while (!ch.empty())
//     {
//         char t = ch.top();
//         ch.pop();
//         if (t == '+' || t == '-')
//         {
//             int second = num.top();
//             num.pop();
//             int first = num.top();
//             num.pop();
//             if (t == '+')
//             {
//                 num.emplace(first + second);
//             }
//             else
//             {
//                 num.emplace(first - second);
//             }
//         }
//     }
//     return num.top();
// }

int calculate(string s)
{
    vector<int> stk;
    char preSign = '+';
    int num = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i)
    {
        if (isdigit(s[i]))
        {
            num = num * 10 + int(s[i] - '0');
        }
        if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1)
        {
            switch (preSign)
            {
            case '+':
                stk.push_back(num);
                break;
            case '-':
                stk.push_back(-num);
                break;
            case '*':
                stk.back() *= num;
                break;
            default:
                stk.back() /= num;
            }
            preSign = s[i];
            num = 0;
        }
    }
    return accumulate(stk.begin(), stk.end(), 0);
}