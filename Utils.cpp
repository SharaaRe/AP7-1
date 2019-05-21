#include "Utils.h"

#include <iostream>
#include <regex>

#include "Exceptions.h"


using namespace std;

 bool Utils::is_in_string(char character, string checkString)
{
    for (int i = 0; i < checkString.length(); i++)
        if (character == checkString[i])
            return true;
    return false;
}

int Utils::find(string word, vector <string> line)
{
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == word)
            return i;
    }
    return NOT_FOUND;
}


 vector <string> Utils::split_line(string line, string delimiters)
{
    // string delimiters = "   ";
    vector <string>  tokens;
    int start = 0; int length = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (is_in_string(line[i], delimiters))
        {
            if (length > 0)
                tokens.push_back(line.substr(start, length));


            start = i+1;
            length = 0;
        } 
        else
            length++;
    }
    tokens.push_back(line.substr(start, length));


    return tokens;  
}

vector <string> Utils::merge_tokens(int from, int to, vector <string> words)
{
    string merged = words[from];
    for (int i = from + 1; i <= to; i++)
    {
        merged += "/";
        merged += words[i];
        // cout << merged << endl;
    }

    words[from] = merged;
    for (int i = from + 1; i <= to; i++)
    {
        words.erase(words.begin() + i);
    }

    // for (int i = 0; i< words.size(); i++)
    //     cout << words[i] << endl;

    return words;
}

bool Utils::is_valid_email(string email)
{
    auto pattern = R"(^[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,}$)";
    auto rx = std::regex{pattern, std::regex_constants::icase};
    return std::regex_match(email, rx);
}

bool Utils::is_valid_number(string number)
{
    if (number.empty())
        return false;
    for (int i = 0; i < number.size(); i++)
        if (!isdigit(number[i]))
            return false;
    return true;
}


int Utils::string_integer_value(string number)
{
    if (is_valid_number(number))
        return stoi(number);
    else
        throw BadRequest("value is not a number");
}
