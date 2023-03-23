#include <iostream>
using namespace std;

void printString( string s, int first )
{
    for ( int i = first; i < s.length(); i++ )
        cout << s[i];
    cout << endl;
}

int endPre( string strExp, int first )
{    
    cout << "------" << endl;    // Output here
    printString(strExp, first);  // Output here

    int last = strExp.length() - 1;
    if ( first < 0 || first > last ) return -1;
    char ch = strExp[first];
    if ( '0' <= ch && ch <= '9' ) return first;
    else if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' )
    {
        cout << ch << endl;      // Output here
        int endPos = endPre(strExp, first + 1);
        cout << endPos << endl;  // Output here
        if ( endPos > -1 )
            return endPre(strExp, endPos + 1);
        else return -1;
    }
    else return -1;
}

int main() {
  cout << endPre("++23+56", 0);
}