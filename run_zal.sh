mkdir -p zal/build
cd zal/build
clang-format -i --style=file ../foo.hpp
cmake ..
make -j2
./zal
