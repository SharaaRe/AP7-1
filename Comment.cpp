#include "Comment.h"

Comment::Comment(int _id, std::string _content)
    :id(_id), content(_content)
{

}

void Comment::add_reply(std::string _reply)
{
    reply = _reply;
}


std::string Comment::get_reply() const
{
    return reply;
}

std::string Comment::get_content() const
{
    return content;
}

int Comment::get_id() const
{
    return id;
}


