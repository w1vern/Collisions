
#include <cstdint>
#include <string>
#include <fstream>
#include <cmath>

struct Block
{
    double coord;
    const double mass;
    double speed;
};

void counter(std::uint8_t n, std::string fileName)
{
    Block b1{1, 1, 0}, b2{2, std::pow(100, n - 1), -1};
    std::ofstream output;
    output.open(fileName + ".log");

    output << std::fixed;
    output.precision(10);

    double massSum = b1.mass + b2.mass;
    double massDif12 = b1.mass - b2.mass;
    double massDif21 = b2.mass - b1.mass;
    bool state = true;
    while (true)
    {
        if (state)
        {
            double speedSum = b1.speed + b2.speed;
            double newSpeed1 = (massDif12 * b1.speed + 2 * b2.mass * b2.speed) / massSum;
            double newSpeed2 = (massDif21 * b2.speed + 2 * b1.mass * b1.speed) / massSum;
            double newCoord1 = b1.coord + b1.speed / speedSum * (b2.coord - b1.coord);
            double newCoord2 = b2.coord - b2.speed / speedSum * (b2.coord - b1.coord);
            b1.speed = newSpeed1;
            b2.speed = newSpeed2;
            b1.coord = newCoord1;
            b2.coord = newCoord2;
        }
        else
        {
            b2.coord += b2.speed * b1.coord / b1.speed;
            b1.coord = 0;
            b1.speed = -(b1.speed);
        }
        state ^= true;
        output << b1.coord << " " << b1.speed << std::endl;
        output << b2.coord << " " << b2.speed << std::endl;
        output << std::endl;
        if (b2.speed > std::abs(b1.speed) && b2.speed >= 0)
            break;
    }
    output.close();
}