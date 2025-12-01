#include <array>
#include <argparse/argparse.hpp>
#include "report.h"


int main(int argc, char* argv[]) {
    Report report = Report(std::array<int, 5>{0,0,0,0,0});
    report.sayHello();
    return 0;
}
