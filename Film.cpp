#include "Film.h"

#include "Exceptions.h"

using namespace std;

int Film::last_id_created = 0;

Film::Film(string _name, int _year, int _length, int _price, string _summery, string _director)
    : name(name), year(_year), length(_length), summery(_summery), director(_director), available(true)
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

void Film::add_comment(Comment* new_comment)
{
    last_comment_id++;
    comments[id] = new_comment;
}


void Film::reply_comment(int comment_id, string reply_content)
{
    if(comments.find(comment_id) == comments.end())
        throw new NotFound("comment id not found");
    else    ;
        //comment should have reply here, complete it later
}

void Film::delete_comment(int comment_id)
{
    if(comments.find(comment_id) == comments.end())
        throw new NotFound("comment id not found");
    else
        comments.erase(comment_id); 
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








