#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

#define NOT_FOUND -1



class Utils 
{
public:
    int find(std::string word, std::vector <std::string> sentence);
    std::vector <std::string> split_line(std::string line, std::string delimiters);
    bool is_in_string(char character, std::string checkString);

};

#endif