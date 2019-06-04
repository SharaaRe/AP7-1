#ifndef PAGE_HANDLERS_H
#define PAGE_HANDLERS_H

#include "server.hpp"

class PageHandlers:public TemplateHandler
{
public:
    Response* callback(Request*);
    PageHandlers(std::string file_path);
    std::map <std::string, std::string> handle (Request* req);
};

#endif