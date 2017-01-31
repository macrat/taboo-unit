#ifndef __TABOO_UNIT__CASE_H__
#define __TABOO_UNIT__CASE_H__


#include <iostream>
#include <string>

#include "value.h"


namespace Taboo {

struct Case {
    bool valid;
    std::string label;
};

class CaseHandler {
private:
	std::string name;
	Case& c;
	bool set;

    std::string paddedName() {
        return name + std::string(70 - name.length(), ' ');
    }

public:
    CaseHandler(std::string name, Case& c) : name(name), c(c) {
		if(c.label.length() != 0){
			std::cout << paddedName() << "\e[1;30m[....]\e[0m";
		}
		set = false;
    }

    ~CaseHandler() {
        if(set){
			if(c.valid){
				std::cout << "\r\e[37m" << paddedName() << "\e[0m[" << c.label << "]" << std::endl;
			}else{
				std::cout << "\r\e[31m" << paddedName() << "\e[0m[" << c.label << "]" << std::endl;
			}
        }
    }

    template<class T> CaseHandler& operator =(Value<T> v) {
        c.valid = (bool)v;
        c.label = (std::string)v;
		set = true;
        return *this;
    }

	operator std::string() const { return name; }
    operator bool() const { return c.valid; }
	std::string label() const { return c.label; }
};

}

#endif
