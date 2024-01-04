//
// Created by Juan Hurtado on 31/12/23.
//

#ifndef KUY_ACTION_H
#define KUY_ACTION_H

#include <string>

class Action {
public:
    std::string name;
    std::string type;

    Action(const std::string &name, const std::string &type) : name(name), type(type) {}
};

#endif //KUY_ACTION_H
