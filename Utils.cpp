#include "Utils.h"

using namespace std;

bool Utils::is_in_string(char character, string checkString)
{
    for (int i = 0; i < checkString.length(); i++)
        if (character == checkString[i])
            return true;
    return false;
}

int find(string word, vector <string> line)
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
        merged += words[i];
    }

    words[from] = merged;
    for (int i = from + 1; i <= to; i++)
    {
        words.erase(words.begin() + i);
    }

    return words;
}

