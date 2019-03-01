#include "folder.h"
#include "msg.h"

void Folder::addMsg(Message* m) {
    //m_s.insert(m->contents); //error
    //m->save(*this); //error
    m_msg.insert(m);
}
void Folder:: remMsg(const Message* m) {

}