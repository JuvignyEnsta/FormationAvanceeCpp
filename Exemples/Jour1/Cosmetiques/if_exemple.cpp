#include <map>
#include <string>
#include <iostream>


int main()
{
    std::map<int,std::string> keys{ {2,"def"}, {3, "loop"}, {5, "cond"}, {7, "<-"} };
    if ( auto it = keys.find(11); it != keys.end() )
        std::cout << "Longueur clef n°11 : " << it->second.size() << std::endl;
    keys[11] = "equal";
    if ( auto it = keys.find(11); it != keys.end() ) 
        std::cout << "Longueur clef n°11 : " << it->second.size() << std::endl;
    return EXIT_SUCCESS;
}
