#include <iostream>

class Fruit
{
    public:
        enum FruitType
        {
            apple,
            banana,
            orange
        };
    private:
        FruitType m_type {};
        int m_percentageEaton { 0 };

    public:
        Fruit(FruitType type): m_type{ type }, m_percentageEaton{ 0 } { };
        FruitType getType() const
        {
            return m_type;
        }
        int getPercentageEaton() const
        {
            return m_percentageEaton;
        }
};

int main()
{
    Fruit fruit { Fruit::apple };
    if (fruit.getType() == Fruit::apple)
        std::cout << "fruit is apple";
}