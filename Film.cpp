#include "Film.h"

#include "Exceptions.h"
#include "Comment.h"

enum {MIN_SCORE = 0, MAX_SCORE = 10};

constexpr int NOT_ASSIGNED = -1;

using namespace std;

int Film::last_id_created = 0;


Film::Film(string _name, int _year, int _length, int _price, string _summary, string _director, int _publisher_id)
    : name(_name), year(_year), length(_length), price(_price), summary(_summary), 
            director(_director), available(true), publisher_id(_publisher_id)
{
    // id = NOT_ASSIGNED;
    id = ++last_id_created;
    last_comment_id = 0;
    rate = 0;
}


void Film::set_id(int _id)
{
    if (id == NOT_ASSIGNED)
        id = _id;
}

void Film::delete_()
{
    available = false;
}

bool Film::is_available()
{
    return available;
}

void Film::add_comment(std::string content, int writer_id)
{
    last_comment_id++;
    comments[last_comment_id] = Comment(last_comment_id, writer_id,  content);
}


void Film::reply_comment(int comment_id, string reply_content)
{
    if(comments.find(comment_id) == comments.end())
        throw NotFound("comment id not found");
    else
        comments[comment_id].add_reply(reply_content);
}

void Film::delete_comment(int comment_id)
{
    if(comments.find(comment_id) == comments.end())
        throw NotFound("comment id not found");
    else
        comments.erase(comment_id); 
}

void Film::add_score(int id,int score)
{
    if (score >= MIN_SCORE && score <= MAX_SCORE)
        scores[id] = score;
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

void Film::set_summary(string _summary)
{
    summary = _summary;
}

string Film::get_summary()
{
    return summary;
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
    // float _rate = 0;
    int sum = 0;
    if (scores.size() == 0)
        return sum;
    for (map<int, int>::iterator it = scores.begin(); it != scores.end(); it++)
        sum += it->second;
    
    rate = ((float) sum ) / scores.size();
    return rate;
}

int Film::get_publisher_id()
{
    return publisher_id;
}

int Film::get_commenter_id(int comment_id)
{
    if (comments.find(comment_id) != comments.end())
        return comments[comment_id].get_writer_id();
}

vector <Comment> Film::get_comments()
{
    vector <Comment> res;
    for (map <int, Comment>:: iterator it = comments.begin(); it != comments.end(); it++)
    {
        res.push_back(it->second);
    }

    return res;
}









