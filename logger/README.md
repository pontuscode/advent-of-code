# Logger

This simple logger is inspired by Python's logging module. There are five logger
levels: `DEBUG`, `INFO`, `WARNING`, `ERROR`, and `CRITICAL`. Here's how to use it:

```cpp
#include "logger.h"

int main() {
    Logger logger = Logger();
    // By default, messages of level INFO and higher are enabled
    logger.log(INFO, "Hello!");
    // This won't be logged since we use the default INFO level
    logger.log(DEBUG, "Greetings");
    // change logger threshold
    logger.setLevel(WARNING);
    // This won't be logged since we changed the threshold
    logger.log(INFO, "Hello :)");
}
```
