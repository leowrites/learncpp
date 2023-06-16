//
// Created by Siqi Liu on 2023-06-12.
//

// a flag is a value  that signals when some conditions exist in a program
// bit flags is an efficient way to store some conditions
#include <bitset>

std::bitset<8> bitset {};
// number bits from right to left
// bitset hsa 4 functions for bit manipulation

int main() {
    // use for convinience but not memory savings.
    // bitset rounds # of bits to the nearest sizeof(size_t), so event tho we only want 8 bits, 4 bytes are allocated
    // on a 32 bit machine, and 8 bytes for 64
    std::bitset<8> bits {};
    // test if bit at index is 0 or 1
    bits.test(5);
    // flip the value of the bit (toggle)
    bits.flip(3);
    // set the bit
    bits.set(2);
    // turn all bits off
    bits.reset();

    // bitwise operataion
    // x << y x >> y -- shift all bits in x left/right by y bits
    // ~x -- flip all bits
    // x & y -- each bit in x AND each bit in y
    // x | y bitwise OR
    // x ^ y bitwise XOR

    std::bitset<8> shiftRight { 1000'100};
    // equivalent to shiftRight = shiftRight >> 1;
    shiftRight >>= 1;

    // bitmask -- predefined set of bits used to select which bits will be modified
    // it blocks the bits we don't want modified

}