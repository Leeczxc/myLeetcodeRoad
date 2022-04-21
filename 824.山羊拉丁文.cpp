class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans="";
        unordered_set<char> hei={'a','A','e','E','i','I','o','O','u','U'};
        int n=sentence.size(),n1=0;
        string temp="";
        char t;
        string add="a";
        while(n1<n)
        {
            if(hei.find(sentence[n1])!=hei.end())
            {
                while(n1<n&&sentence[n1]!=' ')
                {
                    temp.push_back(sentence[n1]);
                    n1++;
                }
            }
            else
            {
                t=sentence[n1];
                n1++;
                while(n1<n&&sentence[n1]!=' ')
                {
                    temp.push_back(sentence[n1]);
                    n1++;
                }
                temp.push_back(t);
            }
            temp+="ma";
            ans+=temp+add;
            add.push_back('a');
            temp="";
            if(n1!=n)
                ans.push_back(' ');
            n1++;
        }
        return ans;
    }
};