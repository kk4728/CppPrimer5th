#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <vector>
#include <set>

class Message;

class Folder
{
public:

    void addMsg(Message* m) ;
    void remMsg(const Message* m);

private:
    //std::vector<std::string> m_vs;
    //std::set<std::string> m_s;
    std::set<Message*> m_msg;
};

#endif //FOLDER_H
