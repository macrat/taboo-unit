#include "test.h"
#include "value.h"

using Taboo::V;
using Taboo::Test;


int main() {
    Test t;

    t["boolean check"] = V(true) == true;
    t["boolean must fail"] = V(true) == false;

	t["boolean check is succeed"] = V((bool)t["boolean check"]);
	t["boolean check is failed"] = V((bool)t["boolean must fail"]) == false;

    t["equals / not equals"] = 9 != (10 != (5 == V(10))) == 10 == 20 != 10 != 11;
    t["lt"] = 5 < V(10) < 20 < 10;
    t["le"] = 5 <= V(10) <= 20 <= 10;
    t["lt"] = 11 < V(10) < 20 < 2 < 30;
    t["le"] = 11 <= V(10) <= 20 <= 2 <= 30;
    t["gt"] = 21 > (20 > (50 > V(20))) > 10 > 19 > 20;
    t["ge"] = 21 >= (20 >= (50 >= V(20))) >= 10 >= 19 >= 20;
    t["equal values"] = V(10) == V(10) == V(20) == 20 == V(20) == 10;
    t["not equal values"] = V(10) != V(10) != V(20) != 20 != V(20) != 10;
    t["lt values"] = V(10) < V(10) < V(20) < 20 < V(20) < 10;
    t["gt values"] = V(10) > V(10) > V(20) > 20 > V(20) > 10;
    t["le values"] = V(10) <= V(10) <= V(20) <= 20 <= V(20) <= 10;
    t["ge values"] = V(10) >= V(10) >= V(20) >= 20 >= V(20) >= 10;
    t["logical and"] = V(10) == 10 && V(20) == 20 && V(20) == 30;
    t["logical or"] = V(10) == 10 || V(20) == 20 || V(20) == 30;
}
