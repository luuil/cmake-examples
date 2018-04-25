#include <iostream>
#include <boost/filesystem.hpp>

int main(int argc, char *argv[])
{
    std::cout << "Hello find_package()!" << std::endl;

    // trivial use of boost filesystem
    boost::filesystem::path path = "/home/luuil";
    if(path.is_relative()) {
        std::cout << "Path is relative" << std::endl;
    } else {
        std::cout << "Path is not relative" << std::endl;
    }

   return 0;
}