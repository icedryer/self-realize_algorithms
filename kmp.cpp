#include <iostream>
using namespace std;
int nextcmp[100];

string pattern;
string mainstr;
void cal()
{
    nextcmp[1] = nextcmp[0] = 0;
    int len = pattern.length();
    for (int i = 2; i < len; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            int flag = 1;
            for (int k = 0; k < j; ++k)
            {
                if (pattern[k] != pattern[k + i - j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                nextcmp[i] = j;
                break;
            }
        }
    }
}
int kmp()
{
    int i = 0, j = 0;
    int lena = pattern.length(), lenb = mainstr.length();
    while (i < lenb && j < lena)
    {
        if (mainstr[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = nextcmp[j];
            }
        }
        // cout<<"P:\n"<<i<<" "<<j<<endl;
    }
    if (j >= lena)
        return i - lena;
    return -1;
}
int main()
{

    cin >> pattern >> mainstr;
    cal();
    // cout<<nextcmp[i]<<" ";
    cout << kmp();
}