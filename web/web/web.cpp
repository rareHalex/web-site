#include <iostream>
#include <experimental/filesystem> // C++ 17
#include "server.hpp"
using namespace std;
namespace fs = std::experimental::filesystem;




int main(int argc, char** argv)
{
    int port{ 11000 }; //for local test 
    if (argc >= 2)
        port = std::stoi(argv[1]);

    server serv(port);
    // trail :
    fs::path path_cert = fs::current_path() / "certificates" / "selfsigned.crt";
    fs::path path_key = fs::current_path() / "certificates" / "selfsigned.key";

    serv.setCertPath(path_cert.string());
    serv.setKeyPath(path_key.string());

    if (!serv.start())
    {
        std::cerr << "server can't  start, Search clue please wait" << std::endl;

    }
    return 0;
}