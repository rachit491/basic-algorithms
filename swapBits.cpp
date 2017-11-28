#include <iostream>

using namespace std;

int swapBits(int num) {
    int even = num & 0xAAAAAAAA;
    int odd = num & 0x55555555;
    
    even >>= 1;
    odd <<= 1;
    
    return (odd | even);
}

int main() {
    cout<<swapBits(23);
    return 0;
}