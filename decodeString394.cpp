class Solution {
public:
pair<string, int> decode(string str, int startPos)
{
    string ans = "";
    int num = 0;
    bool haveNUm = false;
    for (int i = startPos; i < str.size(); ++i)
    {
        if (isdigit(str[i]))
        {
            haveNUm = true;
            if (num != 0)
            {
                num = num * 10 + str[i] - '0';
            }
            else
            {
                num = str[i] - '0';
            }
        }
        else
        {
            switch (str[i])
            {
            case '[':
            {
                auto t = decode(str, i + 1);
                string first = t.first;
                i = t.second;
                for (int x = 0; x < num; x++)
                {
                    ans += first;
                };
                num = 0;
            }
            break;
            case ']':
                return pair<string, int>(ans, i);
            default:
                ans += str[i];
                break;
            }
        }
    }
    return pair<string, int>(ans, str.size());
}

string decodeString(string s)
{

    return decode(s, 0).first;
}

};