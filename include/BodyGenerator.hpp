#pragma once

#include <cmath>
#include <filesystem>
#include <fstream>
#include <random>

#include "Body.hpp"

class BodyGenerator
{
  public:
    BodyGenerator();

    BodyGenerator(std::filesystem::path seed);

    Body generate();

    void saveToCsv(std::size_t n, std::filesystem::path path);

  private:
    std::mt19937_64 randomEngine;

    std::uniform_real_distribution<double> xyDistribution{-5e20, 5e20};

    std::uniform_real_distribution<double> zDistribution{-9e18, 9e18};

    std::uniform_real_distribution<double> massDistribution{1e18, 6e32};
};