class Spreadsheet {
public:
    pair<int,int> parseCell(string cell){
        int col = cell[0] - 'A';       // column index
        int row = stoi(cell.substr(1)) - 1; // row index (convert 1-based to 0-based)
        return make_pair(row, col);
    }

    vector<vector<int>>sp;
    Spreadsheet(int rows) {
        sp.resize(rows, vector<int>(26));
    }
    
    void setCell(string cell, int value) {
        pair<int,int>p = parseCell(cell);
        int r = p.first;
        int c = p.second;
        
        sp[r][c] = value;
    }
    
    void resetCell(string cell) {
        pair<int,int>p = parseCell(cell);
        int r = p.first;
        int c = p.second;

        sp[r][c] = 0;
    }
    
    int getValue(string formula) {
        int idx = formula.find_first_of('+');
        string a = formula.substr(1, idx-1);
        string b = formula.substr(idx+1);

        
        // check if a is all digits like 7 or alnum like A1
        string a1 = a;
        sort(begin(a1), end(a1));
        cout<<"a1 "<<a1<<"\n";
        int n1 = 0;
        // if after sorting a -> it is like 1A -> then it is alnum
        if(isdigit(a1[a1.size()-1]) == true){ // then its a number
            n1 = stoi(a);
        }else{
            // its a A1 like format
            pair<int,int>p = parseCell(a);
            int r = p.first;
            int c = p.second;
            cout<<"here";
            n1 = sp[r][c];
        }
        cout<<"n1 "<<n1<<" ";

        // for b also
        string b1 = b;
        sort(begin(b1), end(b1));
        // cout<<" b1 "<<b1<<"\n";
        int n2 = 0;
        if(isdigit(b1[b1.size()-1])==true){
            n2 = stoi(b);
        }else{
            pair<int,int>p = parseCell(b);
            int r = p.first;
            int c = p.second;

            n2= sp[r][c];
        }
        // cout<<"n2 "<<n2<<"\n";
        return n1+n2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */