#include <iostream>
#include <unordered_map>
#include <vector>
#include <regex>
using namespace std;

class Main {
    unordered_map<string, string> statements;
    vector<string> result;
    vector<string> operators {"+", "*"};
public:
    void getStatements() {
    int n;
    cout << "Enter the number of statements:";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string statement;
        cout << "Enter the statement " << i+1 << ": ";
        cin >> statement;
        size_t pos = statement.find("=");
        if (pos == string::npos) {
            cout << "Invalid statement format. Please use the format: variable = expression" << endl;
            i--;
            continue;
        }
        string lhs = statement.substr(0, pos);
        string rhs = statement.substr(pos + 1);
        statements[lhs] = rhs;
        result.push_back(lhs);
        }
    }

    void putStatements() {
        for (const string& lhs : result) {
            cout << lhs << " : " << statements[lhs] << endl;
        }
        cout << "----------------------------------------" << endl;
    }
    int evaluate(const string& str) {
        string strCopy = str; // Make a copy of the input string
        vector<string> arr;
        size_t pos = 0;
        while ((pos = strCopy.find("+")) != string::npos) {
            arr.push_back(strCopy.substr(0, pos));
            strCopy.erase(0, pos + 1);
        }
        arr.push_back(strCopy);
        for (string& num : arr) {
            int result = 1;
            size_t mulPos = 0;
            while ((mulPos = num.find("*")) != string::npos) {
                int a = stoi(num.substr(0, mulPos));
                int b = stoi(num.substr(mulPos + 1));
                result = a * b;
                num = to_string(result);
            }
        }
        int sum = 0;
        for (const string& num : arr) {
            sum += stoi(num);
        }
        return sum;
    }
    void constantFolding() {
        for (const string& lhs : result) {
            string rhs = statements[lhs];
            regex pattern("\\d+([+*]\\d+)+");
            smatch m;
            while (regex_search(rhs, m, pattern)) {
                string subexpr = m.str();
                int result = evaluate(subexpr);
                rhs = regex_replace(rhs, pattern, to_string(result));
            }
            statements[lhs] = rhs;
        }
    }
     void variablePropagation()
    {
        for (int i = 0; i < result.size(); i++)
        {
            string lhs1 = result[i];
            string rhs1 = statements[lhs1];
            if (rhs1.length() == 1 && find(result.begin(), result.end(), rhs1) != result.end())
            {
                for (int j = 0; j < result.size(); j++)
                {
                    string lhs2 = result[j];
                    string rhs2 = statements[lhs2];
                    size_t found = rhs2.find(lhs1);
                    if (found != string::npos)
                    {
                        rhs2.replace(found, lhs1.length(), rhs1);
                        statements[lhs2] = rhs2;
                    }
                }
                result.erase(find(result.begin(), result.end(), lhs1));
                statements.erase(lhs1);
            }
        }
    }
    void commonSubexpElim() {
        for (const string& lhs1 : result) {
            string rhs1 = statements[lhs1];
            for (const string& lhs2 : result) {
                string rhs2 = statements[lhs2];

                if (lhs1 == lhs2) {
                    continue;
                }
                size_t found = rhs1.find(rhs2);
                if (found != string::npos) {
                    rhs1.replace(found, rhs2.length(), lhs2);
                    statements[lhs1] = rhs1;
                }
            }
        }
    }
};
int main() {
    Main obj;
    obj.getStatements();
    cout << "Initially statements are: " << endl;
    obj.putStatements();
    obj.constantFolding();
    cout << "After constant folding: " << endl;
    obj.putStatements();
    obj.variablePropagation();
    cout << "After variable propagation: " << endl;
    obj.putStatements();
    obj.commonSubexpElim();
    cout << "After common subexpression elimination: " << endl;
    obj.putStatements();
    return 0;
}
