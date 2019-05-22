#include "Film.h"

#include "Exceptions.h"
#include "Comment.h"

enum {MIN_SCORE = 0, MAX_SCORE = 10};

using namespace std;

int Film::last_id_created = 0;

Film::Film(string _name, int _year, int _length, int _price, string _summery, string _director, int _publisher_id)
    : name(name), year(_year), length(_length), summery(_summery), director(_director), available(true), publisher_id(_publisher_id)
{
    last_id_created++;
    id = last_id_created;
    last_comment_id = 0;
    rate = 0;
}

void Film::delete_()
{
    available = false;
}

bool Film::is_available()
{
    return available;
}

void Film::add_comment(std::string content)
{
    last_comment_id++;
    comments[last_comment_id] = Comment(last_comment_id, content);
}


void Film::reply_comment(int comment_id, string reply_content)
{
    if(comments.find(comment_id) == comments.end())
        throw new NotFound("comment id not found");
    else
        comments[comment_id].add_reply(reply_content);
}

void Film::delete_comment(int comment_id)
{
    if(comments.find(comment_id) == comments.end())
        throw new NotFound("comment id not found");
    else
        comments.erase(comment_id); 
}

void Film::add_score(int score)
{
    if (score >= MIN_SCORE && score <= MAX_SCORE)
        scores.push_back(score);
    else
        throw BadRequest("rate range is not right");
}


void Film::set_name(string _name)
{
    name = _name;
}

string Film::get_name()
{
    return name;
}

void Film::set_year(int _year)
{
    year = _year;
}


int Film::get_year()
{
    return year;
}

void Film::set_length(int _length)
{
    year = _length;
}


int Film::get_length()
{
    return length;
}

void Film::set_summery(string _summery)
{
    summery = _summery;
}

string Film::get_summemry()
{
    return summery;
}

void Film::set_director(string _director)
{
    director = _director;
}

string Film::get_director()
{
    return director;
}

int Film::get_price()
{
    return price;
}

int Film::get_id()
{
    return id;
}

float Film::get_rate()
{
    float _rate = 0;
    int sum;
    for (int i = 0; i < scores.size(); i++)
        sum += scores[i];
    
    rate = ((float) sum ) / scores.size();
    return rate;
}

int Film::get_publisher_id()
{
    return publisher_id;
}











