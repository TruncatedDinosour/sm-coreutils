#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    while (argc == 1)
        std::cout << "y\n";

    std::string final_str;

    for (int idx = 1; idx < argc; ++idx) {
        final_str += argv[idx];

        if (idx + 1 < argc)
            final_str += " ";
    }

    while (true)
        std::cout << final_str << '\n';

    return 0;
}
