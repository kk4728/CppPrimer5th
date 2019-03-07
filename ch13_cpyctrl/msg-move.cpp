#include <string>
#include <set>
#include <vector>
#include <iostream>

#include "folder.h"

class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);

public:
    explicit Message(const std::string &str = "") :
        contents(str) {}

    Message(const Message& m) {
        add_to_Folders(m);
    }
    Message& operator=(const Message& rhs) {
        remove_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_Folders(rhs);
        return *this;
    }
    ~Message() {
        remove_from_Folders();
    }

    Message(Message &&m) : contents(std::move(m.contents)) {
        //移动folders并更新Folder指针
        move_Folders(&m); 
        std::cout << "move constructor." << std::endl;
    }
    //与任何赋值运算符一样，移动赋值运算符也必须销毁左侧运算对象的旧状态
    Message& operator=(Message &&rhs) {
        if(this != &rhs) { //直接检查自赋值情况
            remove_from_Folders();
            contents = std::move(rhs.contents); //移动赋值运算符
            move_Folders(&rhs); //重置Folders指向本Message
        }
        return *this;
    }
    void move_Folders(Message* m) {
        folders = std::move(m->folders); //使用set的移动赋值运算符
        for (auto f : folders) {
            f->remMsg(m); //从Folder中删除旧的Message
            f->addMsg(this); //将Message添加到Foler中
        }
        m->folders.clear(); // 确保销毁m是无害的
    }

    void save(Folder& f) {
        folders.insert(&f);
        f.addMsg(this);
    }
    void remove(Folder& f) {
        folders.erase(&f);
        f.remMsg(this);
    }

private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_Folders(const Message& m) {
        for(auto f: m.folders)
            f->addMsg(this);
    }
    void remove_from_Folders() {
        for(auto f : folders)
            f->remMsg(this);
    }
};


void swap(Message& lhs, Message& rhs) {
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

int main()
{
    Message m1;
    Message m2 = std::move(m1);

    return 0;
}