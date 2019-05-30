#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>


#define NOT_FOUND -1
enum {BY_NAME, BY_RATE, BY_PRICE, BY_MIN_YEAR, BY_MAX_YEAR, BY_DIRECTOR};

class Film;

class Utils 
{
public:
    Utils() {};
    static int find(std::string word, std::vector <std::string> sentence);
    static std::vector <std::string> merge_tokens(int from, int to, std::vector <std::string> words);
    static std::vector <std::string> split_line(std::string line, std::string delimiters);
    static bool is_in_string(char character, std::string checkString);
    static bool is_valid_email(std::string email);
    static bool is_valid_number(std::string number);
    static int string_integer_value(std::string number);
    // std::vector <Film> filter(int filter_key);
// private:
    // int something_alaki;

};

#endif