#include <iostream>
#include <ctype.h>

int myAtoi(std::string s)
{
    // I paid for the memory, so I'm gonna use all the memory :)
    char str[INT8_MAX] = {0};
    int index = 0;
    bool read_num = false;
    bool found_sign = false;
    bool error = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
        {
            continue;
        }

        if ((s.at(i) == '+') && !read_num)
        {
            if (!found_sign)
            {
                found_sign = true;
            }
            else
            {
                error = true;
                break;
            }
            continue;
        }

        if ((s.at(i) == '-') && !read_num)
        {
            if (!found_sign)
            {
                found_sign = true;
                str[index] = '-';
                index++;
            }
            else
            {
                error = true;
                break;
            }
            continue;
        }

        if (std::isdigit(s.at(i)))
        {
            read_num = true;
            str[index] = s.at(i);
            index++;
            continue;
        }

        if (s.at(i) == '.')
        {
            break;
        }

        if (!std::isdigit(s.at(i)) && !read_num)
        {
            break;
        }
    }

    if (str[0] == '-' && !std::isdigit(str[1]))
    {
        error = true;
    }

    if (str[0] == '+' && !std::isdigit(str[1]))
    {
        error = true;
    }

    str[index] = '\0';

    if (!error && str[0] != 0)
    {
        long val = std::stol(std::string(str));
        if (val > INT32_MAX)
        {
            val = INT32_MAX;
        }
        else if (val < INT32_MIN)
        {
            val = INT32_MIN;
        }
        return (int)val;
    }
    else
    {
        return 0;
    }
}


int main()
{

    std::cout << myAtoi("   -42") << std::endl;
    std::cout << myAtoi("1234 with chars") << std::endl;
    std::cout << myAtoi("at front987") << std::endl;
    std::cout << myAtoi("yeet") << std::endl;
    std::cout << myAtoi("--57-") << std::endl;

    return 0;
}