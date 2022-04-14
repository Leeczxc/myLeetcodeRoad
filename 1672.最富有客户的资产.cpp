int maximumWealth(vector<vector<int>>& accounts) {
    int res = 0;
    for (auto accounts: accounts) {
        int sum = 0;
        for (auto money: accounts)
            sum += money;
        if (sum > res)
            res = sum;
    }
    return res;
}
