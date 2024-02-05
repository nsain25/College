#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> productions;
    string ip, op1, op2;
    int n, j, l;
    char c;
    cout << "Enter the Parent Non-Terminal : ";
    cin >> c;
    ip.push_back(c);
    op1 += ip + "\'->";
    ip += "->";
    op2 += ip;
    cout << "Enter the number of productions : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cout << "Enter Production " << i + 1 << " : ";
        cin >> temp;
        productions.push_back(temp);
        ip += temp;
        if (i != n - 1)
            ip += "|";
    }
    cout << "Production Rule : " << ip << endl;
    for (int i = 0, k = 3; i < n; i++)
    {
        if (ip[0] == ip[k])
        {
            cout << "Production " << i + 1 << " has left recursion." << endl;
            if (ip[k] != '#')
            {
                for (l = k + 1; l < k + productions[i].size(); l++)
                    op1.push_back(ip[l]);
                k = l + 1;
                op1.push_back(ip[0]);
                op1 += "\'|";
            }
        }
        else
        {
            cout << "Production " << i + 1 << " does not have left recursion." << endl;
            if (ip[k] != '#')
            {
                for (j = k; j < k + productions[i].size(); j++)
                    op2.push_back(ip[j]);
                k = j + 1;
                op2.push_back(ip[0]);
                op2 += "\'|";
            }
            else
            {
                op2.push_back(ip[0]);
                op2 += "\'";
            }
        }
    }
    op1 += "#";
    cout << op2 << endl;
    cout << op1 << endl;
    return 0;
}
