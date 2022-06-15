#include <iostream>
#include <vector>
#include <string>

bool isValid(std::string s)
{
    std::vector<char> last_known;
    bool valid = false;

    if (s.length() < 2)
        return false;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            last_known.push_back(s[i]);
        }
        else
        {

            if (last_known.size() == 0)
                return false;

            switch (last_known.back())
            {
            case ('('):
                s[i] == ')' ? valid = true : valid = false;
                break;
            case ('{'):
                s[i] == '}' ? valid = true : valid = false;
                break;
            case ('['):
                s[i] == ']' ? valid = true : valid = false;
                break;
            }

            if (!valid)
                break;

            last_known.pop_back();
        }
    }

    if (last_known.size() > 0)
        return false;

    return valid;
}

int main()
{
    std::cout << isValid("{[]}((") << std::endl;
    return 0;
}