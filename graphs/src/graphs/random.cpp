#include <cstdlib>

int randomInteger(int start, int end) {
    return start + rand() % (end - start);
}