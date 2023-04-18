#include <bits/stdc++.h>
using namespace std;
vector<string> res;
int j = 0;
vector<string> D = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"};
void generate(string s)
{
    if (s.length() == 0)
        return;
    if (s.length() == 1)
        return;
    bool flag = false;
    bool flag2 = false;
    string temp = "";
    string k = "";
    string t1 = "";
    string t2 = "";
    for (auto it : s)
    {
        if (flag == false && flag2 == false)
            t1 += it;
        if (flag2 == true)
            t2 += it;
        if (it == ')')
        {
            flag2 = true;
            flag = false;
        }
        if (flag == true)
        {
            temp += it;
        }
        if (it == '(')
        {
            flag = true;
        }
    }
    if (temp != "")
    {
        cout << temp << endl;
        generate(temp);
        s = t1.substr(0, t1.size() - 1) + res[res.size() - 1][0] + t2;
    }
    temp = "";
    k = "";
    if (s[0] == '-')
    {
        string x = D[j];
        temp = x + '=' + '-' + s[1];
        res.push_back(temp);
        s = x + s.substr(2, s.size() - 2);
        j++;
        generate(s);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (i > 0 && (s[i - 1] == '=' || s[i - 1] == '*' || s[i - 1] == '/' || s[i - 1] == '+' || s[i - 1] == '-') && s[i] == '-')
        {
            string x = D[j];
            temp = x + '=' + '-' + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '%')
        {
            string x = D[j];
            temp = x + '=' + s[i - 1] + s[i] + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i - 1) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '/')
        {
            string x = D[j];
            temp = x + '=' + s[i - 1] + s[i] + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i - 1) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '*')
        {
            string x = D[j];
            temp = x + '=' + s[i - 1] + s[i] + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i - 1) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+')
        {
            string x = D[j];
            temp = x + '=' + s[i - 1] + s[i] + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i - 1) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-')
        {
            string x = D[j];
            temp = x + '=' + s[i - 1] + s[i] + s[i + 1];
            res.push_back(temp);
            k = s.substr(0, i - 1) + x;
            if (s.length() > i + 2)
            {
                k += s.substr(i + 2, s.size() - i - 2);
            }
            s = k;
            j++;
            generate(s);
            return;
        }
    }
    if (s[1] == '=')
        res.push_back(s);
}
void show()
{
    for (auto it : res)
    {
        cout << it << endl;
    }
}
int main()
{

    string s;
    cout << "Enter an valid expression(without spaces):-" << endl;
    int f = 1;
    cin >> s;
    int l = 0;
    vector<string> vs = {"(", ")", "+", "-", "/", "%", "*"};
    // 2 ek saath
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        string h = "";
        h += c;
        auto it = find(vs.begin(), vs.end(), h);
        if (it != vs.end())
        {
            l++;
        }
        else
        {
            l = 0;
        }
        if (l == 2)
        {
            f = 0;
            // cout<<f<<endl;
            break;
        }
    }
    // 2 saath me terminal
    vector<string> vk = {"a", "b", "c", "d", "e", "f"};
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        string h = "";
        h += c;
        auto it = find(vk.begin(), vk.end(), h);

        if (it != vk.end())
        {
            l++;
        }
        else
        {
            l = 0;
        }
        if (l == 2)
        {
            f = 0;
            // cout<<f<<endl;
            break;
        }
    }
    // Opening and closing
    int op = 0;
    int cl = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (op == 1)
        {
            if (s[i] == ')')
            {
                op--;
            }
            else if (s[i] == '(')
            {
                f = 0;
                break;
            }
        }
        else if (cl == 1)
        {
            if (s[i] == '(')
            {
                cl--;
            }
            else if (s[i] == ')')
            {
                f = 0;
                break;
            }
        }
        else
        {
            if (s[i] == ')')
            {
                cl++;
            }
            else if (s[i] == '(')
            {
                op++;
            }
        }
    }
    // cout<<op<<cl;
    vector<string> vp = {"(", ")", "+", "/", "%", "*", "="};
    if (op > 0 || cl > 0)
    {
        f = 0;
    }
    char cp = s[s.size() - 1];
    string hp = "";
    hp += cp;
    auto it = find(vp.begin(), vp.end(), hp);

    if (it != vp.end())
    {
        f = 0;
    }
    vector<string> vl = {"(", ")", "+", "/", "%", "*", "="};
    char cm = s[0];
    string hm = "";
    hm += cm;
    auto ip = find(vl.begin(), vl.end(), hm);

    if (ip != vl.end())
    {
        f = 0;
    }
    if (f)
    {
        generate(s);
        show();
        res.clear();
    }
    else
    {
        cout << "Not a valid expression";
    }

    return 0;
}