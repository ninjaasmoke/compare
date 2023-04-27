#include <cstdlib>

int main() {
    while (true) {
        int *x = new int[1000];
        delete[] x;
    }
    return 0;
}
