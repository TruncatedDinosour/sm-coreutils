#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    const char *cstr = NULL;
    std::string final_str;

    switch (argc) {
        case 1: // No arguments
            cstr = "y";
            break;
        case 2: // Only one argument (much faster than concating)
            cstr = argv[1];
            break;
    }

    while (cstr)
        std::cout << cstr << '\n';

    // Concating arguments by " "
    // (slower than only one or none argument(s))

    for (int idx = 1; idx < argc; ++idx) {
        final_str += argv[idx];

        if (idx + 1 < argc)
            final_str += " ";
    }

    while (true)
        std::cout << final_str << '\n';

    return 0;
}
