/**
 * @file exemple_string.cpp
 * @author Xavier JUVIGNY (juvigny@onera.fr)
 * @brief Exemples de chaînes de caractères et de leurs manipulation
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std::string_literals;

const std::string chat_ascii = R"CHAT(
          .__....._             _.....__,
            .": o :':         ;': o :".
            `. `-' .'.       .'. `-' .'
              `---'             `---'

    _...----...      ...   ...      ...----..._
 .-'__..-""'----    `.  `"`  .'    ----'""-..__`-.
'.-'   _.--"""'       `-._.-'       '"""--._   `-.`
'  .-"'                  :                  `"-.  `
  '   `.              _.'"'._              .'   `
        `.       ,.-'"       "'-.,       .'
          `.                           .'
            `-._                   _.-'
                `"'--...___...--'"`

)CHAT";

const std::string noel_utf8 = (const char*)u8R"NOEL(
° :.　 . • ○ ° ★　 .　 *　.
★ ° . .　　　　.　☾ °☆　 . * ● ¸ .
∩ │◥███◣ ╱◥███◣
╱◥◣ ◥████◣▓∩▓│∩ ║
│╱◥█◣║∩∩∩ ║◥█▓ ▓█◣
││∩│ ▓ ║∩田│║▓ ▓ ▓∩ ║
)NOEL";

const std::vector fichiers{
    "readme.md"s,
    "database.db"s,
    "programme.cpp"s,
    "data.dat"s,
    "lisezmoi.md"s
};

int main()
{
    std::cout << chat_ascii;
    std::cout << noel_utf8;

#   if (__cplusplus >= 202002L)
    for ( std::string const& nom : fichiers )
    {
        if (nom.starts_with("data")) std::cout << nom << " contient des données." << std::endl;
        if (nom.ends_with(".md")) std::cout << nom << " contient de la documentation en markdown" << std::endl;
    }
#   endif
    return EXIT_SUCCESS;

}
