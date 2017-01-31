#ifndef __TABOO_UNIT__TEST_H__
#define __TABOO_UNIT__TEST_H__


#include <string>

#include "case.h"


namespace Taboo {

class Test {
private:
    int success;
    int count;

public:
    Test() {
        success = 0;
        count = 0;
    }

    Case operator [](std::string name) {
        return { name };
    }
};

}

#endif
