#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'toolchanger' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY tools
 *  2. INTEGER startIndex
 *  3. STRING target
 */

int toolchanger(vector<string> tools, int startIndex, string target) {
     int c1=int(10e9),c2=int(10e9);
     for(int i=startIndex-1;i>=0;i--)
     {
         if(tools[i]==target)
         c1=startIndex-i;
     }
     for(int i=startIndex+1;i<tools.size();i++)
     {
         if(tools[i]==target)
         c2=i-startIndex;
     }
     c1=min(c1,c2);
     return c1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string tools_count_temp;
    getline(cin, tools_count_temp);

    int tools_count = stoi(ltrim(rtrim(tools_count_temp)));

    vector<string> tools(tools_count);

    for (int i = 0; i < tools_count; i++) {
        string tools_item;
        getline(cin, tools_item);

        tools[i] = tools_item;
    }

    string startIndex_temp;
    getline(cin, startIndex_temp);

    int startIndex = stoi(ltrim(rtrim(startIndex_temp)));

    string target;
    getline(cin, target);

    int result = toolchanger(tools, startIndex, target);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}