#include <iostream>
#include <type_traits>

#include "pack.h"
using namespace pack_detail;

int main() {

    std::cout << "packSize\n";
    std::cout << "empty: " << packSize<> << "\n";
    std::cout << "one type: " << packSize<int> << " \n";
    std::cout << "int, char, double: " << packSize<int, char, double> << " \n\n";

    std::cout << "packIndexToType (1 means true 0 means false) \n";
    std::cout << "is_same_v<0, int, char, double>, int> is int for first element: " << std::is_same_v<packIndexToType<0, int, char, double>, int> << "\n";
    std::cout << "is_same_v<2, int, char, double>, double> is double for last element?:  " << std::is_same_v<packIndexToType<2, int, char, double>, double> << "\n";
    std::cout << "is_same_v<0, int, char>, char> is char for first element? : " << std::is_same_v<packIndexToType<0, int, char>, char> << " \n\n";

    std::cout << "packTypeToIndex\n";
    std::cout << "searching int in a empty pack <int>: " << packTypeToIndex<int> << "\n";
    std::cout << "searching double in a pack. (last element) <double, int, char, double>: " << packTypeToIndex<double, int, char, double> << "\n";
    std::cout << "searching float in not a pack: (Not present) <float, int, char, double> " << packTypeToIndex<float, int, char, double> << "\n";
    std::cout << "searching char where there are multiple: (first occurence) <char, int, char, char>: " << packTypeToIndex<char, int, char, char> << "\n\n";

    using P = Pack<int, char, double, char>;
    std::cout << "Pack members for P = Pack<int, char, double, char>\n";
    std::cout << "P size: " << P::size << "\n";
    std::cout << "return an Empty Pack<> size: " << Pack<>::size << "\n";
    std::cout << "testing is_same_v<P::type<0>, int: " << std::is_same_v<P::type<0>, int> << "\n";
    std::cout << "testing std::is_same_v<P::type<3>, char> " << std::is_same_v<P::type<3>, char> << "\n";
    std::cout << "P index<char>: " << P::index<char> << "\n";
    std::cout << "P index<float> (no float in pack): " << P::index<float> << "\n";

    return 0;
}
