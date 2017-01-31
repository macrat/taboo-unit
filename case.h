#ifndef __TABOO_UNIT__CASE_H__
#define __TABOO_UNIT__CASE_H__


#include <iostream>
#include <string>

#include "value.h"


namespace Taboo {

class Case {
private:
    std::string name;
    bool valid;
    std::string label;

    std::string paddedName() {
        return name + std::string(70 - name.length(), ' ');
    }

public:
    Case(std::string name) : name(name) {
        valid = true;
        std::cout << name << paddedName() << "\e[1;30m[....]\e[0m";
    }

    ~Case() {
        if(label.length() == 0){
            std::cout << "\r\e[37m" << paddedName() << "\e[0m[DONE]" << std::endl;
        }else if(valid){
            std::cout << "\r\e[37m" << paddedName() << "\e[0m[" << label << "]" << std::endl;
        }else{
            std::cout << "\r\e[31m" << paddedName() << "\e[0m[" << label << "]" << std::endl;
        }
    }

    template<class T> Case& operator =(Value<T> v) {
        valid = (bool)v;
        label = (std::string)v;
        return *this;
    }

    operator bool() const { return valid; }
};

}

#endif
