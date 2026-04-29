#include <xtensor/xarray.hpp>
#include <iostream>

int main() {
    xt::xarray<double> arr = {1.0, 2.0, 3.0, 4.0};
    std::cout << "Número de elementos: " << arr.size() << std::endl;
    return 0;
}