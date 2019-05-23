#include "Comment.h"

Comment::Comment(int _id, int _writer_id, std::string _content)
    :id(_id), writer_id(_writer_id), content(_content)
{

}

void Comment::add_reply(std::string _reply)
{
    reply.push_back(_reply);
}


int Comment::get_id() const 
{
    return id;
}

int Comment:: get_writer_id()
{
    return writer_id;
}

std::vector <std::string> Comment::get_reply() const
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


