#include "pack.h"
#include "iostream"
#include <type_traits> 
using namespace pack_detail;
int main() { 
    std::cout << pack_detail::packSize<int, char, double> << "\n";
    std::cout << pack_detail::packSize<> << "\n";
    std::cout << std::is_same_v<packIndexToType<0, int, char>, int> << " "
          << std::is_same_v<packIndexToType<1, int, char>, char> << "\n";
    std::cout << packTypeToIndex<char, int, char, char> << " " << packTypeToIndex<float, int> << "\n";
    return 0;
}
