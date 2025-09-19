class Spreadsheet {
public:
    vector<vector<int>> sp;

    Spreadsheet(int rows) {
        sp.resize(rows, vector<int>(26, 0)); // rows × 26 grid
    }

    pair<int,int> parseCell(const string& cell) {
        int col = cell[0] - 'A';                 // column (0-based)
        int row = stoi(cell.substr(1)) - 1;      // row (1-based → 0-based)
        return {row, col};
    }

    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        sp[r][c] = value;
    }

    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        sp[r][c] = 0;
    }

    int getValue(string formula) {
        // formula looks like "=X+Y"
        formula = formula.substr(1); // remove '='
        int plusPos = formula.find('+');
        string a = formula.substr(0, plusPos);
        string b = formula.substr(plusPos + 1);

        return getOperandValue(a) + getOperandValue(b);
    }

private:
    int getOperandValue(const string& token) {
        if (isdigit(token[0])) {
            return stoi(token); // it's a number
        } else {
            auto [r, c] = parseCell(token);
            return sp[r][c];   // it's a cell
        }
    }
};