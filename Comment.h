#ifndef COMMENTS_H
#define COMMENTS_H

#include <string>

class Comment 
{
public:
    Comment() = default;
    Comment(int id, std::string content);
    void add_reply(std::string reply);
    int get_id() const;
    std::string get_content() const;
    std::string get_reply() const;
private:
    int id;
    std::string content;
    std::string reply;
};

#endif