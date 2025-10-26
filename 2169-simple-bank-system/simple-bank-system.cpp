class Bank {
public:
    vector<long long>bal;
    int n;
    bool isBetween1andN(int i){
        if(i>=1 && i<=n)return true;
        return false;
    }
    bool paisaHai(int i, long long money){
        i-=1;
        if(money <= bal[i]) return true;
        return false;
    }

    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(isBetween1andN(account1) && isBetween1andN(account2) && paisaHai(account1, money)){
            bal[account1-1]-=money;
            bal[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(isBetween1andN(account)){
            bal[account-1]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(isBetween1andN(account) && paisaHai(account, money)){
            bal[account-1]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */