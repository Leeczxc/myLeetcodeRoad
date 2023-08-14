#include <iostream>
#include <vector>

using namespace std;

vector<string> ans;
string path = "";
int length = 0;
int cat = 0;

bool isTrue(string &str)
{
    if(str.size() > 3)
        return false;
    if(str.size() > 1 && str[0] == '0')
        return false;
    int num = stoi(str);
    if (num >= 0 && num <= 255)
        return true;
    return false;
}
void backtracing(string s, int startIndex)
{
    if (length == s.size() && cat == 4)
    {
        path.erase(--path.end());
        ans.emplace_back(path);
        return;
    }
    else if (cat == 4 || length == s.size())
    {
        return;
    }
    string str = "";
    for (int i = startIndex; i < s.size(); i++)
    {
        str += s[i];
        length = i + 1;
        if (isTrue(str))
        {
            cat++;
            path += str;
            path += '.';
            backtracing(s, i + 1);
            if(length == s.size() && cat == 4)
                path = path.substr(0, path.size() - str.size());
            else
                path = path.substr(0, path.size() - str.size() - 1);
            cat--;
        }
        length = i + 1;
    }
}
vector<string> restoreIpAddresses(string s)
{
    backtracing(s, 0);
    return ans;
}

int main()
{
    string s = "25525511135";
    auto ans = restoreIpAddresses(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}