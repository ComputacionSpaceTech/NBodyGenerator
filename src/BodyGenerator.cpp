#include <limits>

#include "BodyGenerator.hpp"

BodyGenerator::BodyGenerator() : randomEngine{std::random_device{}()}
{
}

BodyGenerator::BodyGenerator(std::filesystem::path seed)
{
    if (std::filesystem::exists(seed))
    {
        std::ifstream is{seed, std::ios::in};
        is >> randomEngine;
    }
    else
    {
        randomEngine.seed(std::random_device{}());
        std::ofstream os{seed, std::ios::out | std::ios::trunc};
        os << randomEngine;
    }
}

Body BodyGenerator::generate()
{
    return Body{xyDistribution(randomEngine), xyDistribution(randomEngine), zDistribution(randomEngine),
                massDistribution(randomEngine)};
}

void BodyGenerator::saveToCsv(std::size_t n, std::filesystem::path path)
{
    std::ofstream os{path.concat(".csv"), std::ios::out | std::ios::trunc};
    os << "x_position,y_position,z_position,mass\n";

    for (std::size_t i = 0; i < n; i++)
    {
        auto b = generate();
        os << std::fixed << std::setprecision(std::numeric_limits<double>::max_digits10) << b.position.x() << ","
           << b.position.y() << "," << b.position.z() << "," << b.mass << '\n';
    }
}
