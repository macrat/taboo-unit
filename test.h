#ifndef __TABOO_UNIT__TEST_H__
#define __TABOO_UNIT__TEST_H__


#include <string>
#include <map>

#include "case.h"


namespace Taboo {

class Test {
private:
    int success;
    int count;
    std::map<std::string, Case*> cases;

public:
    Test() {
        success = 0;
        count = 0;
    }

    CaseHandler operator [](std::string name) {
        if(cases.find(name) == cases.end()){
            cases[name] = new Case{ valid: true, label: "" };
        }
        return { name, *cases[name] };
    }
};

}

#endif
