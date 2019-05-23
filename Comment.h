#ifndef COMMENTS_H
#define COMMENTS_H

#include <string>
#include <vector>

class Comment 
{
public:
    Comment() = default;
    Comment(int id, int writer_id, std::string content);
    void add_reply(std::string reply);
    int get_id() const;
    int get_writer_id();
    std::string get_content() const;
    std::vector <std::string> get_reply() const;
private:
    int id;
    int writer_id;
    std::string content;
    std::vector <std::string> reply;
};

#endif