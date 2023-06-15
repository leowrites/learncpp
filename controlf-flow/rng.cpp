// random number generation
#include <random>
#include <iostream>
#include <chrono>
// only use Mersenne Twister algorithm, but the problem is the reslts can be predicted after seeing 624 generated numbers
// if high quality randomnized results, then need to use 3rd prty library
void randomExample()
{
    // seeding with the system clock
    std::mt19937 mt{
        static_cast<std::mt19937::result_type>(
            std::chrono::steady_clock::now().time_since_epoch().count()
        )
    };
    // to configure a uniform distribution
    std::uniform_int_distribution<> die{ 1, 6 };
    for (int count { 1 }; count <= 40; ++count)
    {
        // generate a random number
        // mt() implicityly calls mt.operator()
        std::cout << die(mt) << '\t';
    }
    // seeding with random device
    // always try to use this, don't reseed 
    std::mt19937 mt{ std::random_device{}() };
}