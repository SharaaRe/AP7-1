#ifndef FILMS_H
#define FILMS_H

#include <string>
#include <vector>
#include <map>

#define NOT_CHANGED "not changed"
#define VALUE_NOT_CHANGED  -1

#include "Comment.h"

class Film
{
public:
    Film(std::string name, int year, int length, int price, std::string summery, std::string director, int publisher_id);
    void delete_();
    bool is_available();
    void add_comment(std::string comment_content, int writer_id);
    void reply_comment(int comment_id, std::string reply_content);
    void delete_comment(int comment_id);
    void add_score(int score);


    void set_name(std::string name);
    std::string get_name();
    void set_year(int year);
    int get_year();
    void set_length(int length);
    int get_length();
    void set_summery(std::string summery);
    std::string get_summemry();
    void set_director(std::string director);
    std::string get_director();
    int get_price();
    int get_id();
    float get_rate();
    int get_publisher_id();
    int get_commenter_id(int comment_id);
    std::vector <Comment> get_comments();


private:
    static int last_id_created;
    int id;
    std::string name;
    int year;
    int length; //minutes
    int price;
    std::string summery;
    std::string director;
    bool available;

    int publisher_id;

    std::map <int, Comment> comments;
    int last_comment_id;
    std::vector <int> scores;

    float rate;
};

#endif