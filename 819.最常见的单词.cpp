string mostCommonWord(string paragraph, vector<string>& banned) {
    set<string> ban;
    for(auto c : banned){
        ban.insert(c);
    }
    map<string, int> allPara;
    string s = "";
    for(auto c : paragraph){
        if(isalpha(c)){
            if( c >= 'A' && c <= 'Z')
                c = tolower(c);
            s += c;
        }
        else{
            if(s != "" && ban.find(s) == ban.end())
                allPara[s]++;
            s = "";
        }
    }
    if(s != "")
        if(ban.find(s) == ban.end())
            allPara[s]++;
    string res;
    int resNu = -1;
    auto c = allPara.begin();
    while(c != allPara.end()){
        if(c->second > resNu){
            resNu = c->second;
            res = c->first;
        }
        c++;
    }
    return res;
}

int main(){
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    cout << mostCommonWord(paragraph,banned);
}