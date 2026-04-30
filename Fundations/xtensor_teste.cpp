#include <xtensor/containers/xarray.hpp>
#include <xtensor/io/xio.hpp>

#include <iostream>

int main() {

    xt::xarray<double> arr = {{1.0, 2.0}, {3.0, 4.0}};

    std::cout << arr << std::endl;

    return 0;
}


