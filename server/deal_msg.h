#ifndef DEAL_MSG_H
#define DEAL_MSG_H

#include"rlmessage.h"
class deal_msg
{
private:
    QString tmp;
public:
    deal_msg();
    ~deal_msg();
    void deal(rlmessage &str);
};

#endif // DEAL_MSG_H
