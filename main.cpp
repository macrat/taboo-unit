#include "value.h"

using Taboo::V;


int main() {
    std::cout << (V(true) == true) << " -> " << (bool)(V(true) == true) << std::endl;
    std::cout << (V(true) == false) << " -> " << (bool)(V(true) == false) << std::endl;

    std::cout << std::endl;

    std::cout << (9 != (10 != (5 == V(10))) == 10 == 20 != 10 != 11) << std::endl;
    std::cout << (5 < V(10) < 20 < 10) << std::endl;
    std::cout << (5 <= V(10) <= 20 <= 10) << std::endl;
    std::cout << (11 < V(10) < 20 < 2 < 30) << std::endl;
    std::cout << (11 <= V(10) <= 20 <= 2 <= 30) << std::endl;
    std::cout << (21 > (20 > (50 > V(20))) > 10 > 19 > 20) << std::endl;
    std::cout << (21 >= (20 >= (50 >= V(20))) >= 10 >= 19 >= 20) << std::endl;
    std::cout << (V(10) == V(10) == V(20) == 20 == V(20) == 10) << std::endl;
    std::cout << (V(10) != V(10) != V(20) != 20 != V(20) != 10) << std::endl;
    std::cout << (V(10) < V(10) < V(20) < 20 < V(20) < 10) << std::endl;
    std::cout << (V(10) > V(10) > V(20) > 20 > V(20) > 10) << std::endl;
    std::cout << (V(10) <= V(10) <= V(20) <= 20 <= V(20) <= 10) << std::endl;
    std::cout << (V(10) >= V(10) >= V(20) >= 20 >= V(20) >= 10) << std::endl;
    std::cout << (V(10) == 10 && V(20) == 20 && V(20) == 30) <<  " -> " << (bool)(V(10) == 10 && V(20) == 20 && V(20) == 30) << std::endl;
    std::cout << (V(10) == 10 || V(20) == 20 || V(20) == 30) << " -> " << (bool)(V(10) == 10 || V(20) == 20 || V(20) == 30) << std::endl;
}
