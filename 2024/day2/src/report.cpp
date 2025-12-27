#include "report.h"
#include "logger.h"


void Report::sayHello() {
    std::cout << "Hello!" << std::endl;
    Logger logger = Logger();
    logger.log(INFO, "Hello from logger!");
    std::cout << "Trying debug output" << std::endl;
    logger.log(DEBUG, "Hello again :)");
    std::cout << "Setting level and trying again" << std::endl;
    logger.setLevel(DEBUG);
    logger.log(DEBUG, "Hello a third time!");
}
