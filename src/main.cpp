#include "pack.h"
#include "iostream"
int main() { 
    std::cout << pack_detail::packSize<int, char, double> << "\n";
    std::cout << pack_detail::packSize<> << "\n";

    return 0;
}
