#include <sstream>
#include <string>

#include "BodyGenerator.hpp"

int main(int argc, char **argv)
{
    if (argc >= 3)
    {
        std::stringstream stream(argv[1]);
        std::size_t n;
        stream >> n;
        if (argc == 4)
        {
            BodyGenerator bg{argv[3]};
            bg.saveToCsv(n, argv[2]);
        }
        else
        {
            BodyGenerator bg;
            bg.saveToCsv(n, argv[2]);
        }
    }
    else
    {
        BodyGenerator bg;
        bg.saveToCsv(1 << 16, "dataset");
    }

    return 0;
}