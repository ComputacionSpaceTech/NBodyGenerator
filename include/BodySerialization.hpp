#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Body.hpp"

std::vector<Body> loadBodiesCsv(std::filesystem::path path)
{
    std::ifstream is{path.concat(".csv"), std::ios::in};

    std::string header;
    getline(is, header);

    std::cout << "The csv header is:\n" << header << '\n';

    std::vector<Body> bodies;
    std::string line;
    while (std::getline(is, line))
    {
        std::stringstream ss(line);

        std::string value;
        std::getline(ss, value, ',');
        auto x{std::stod(value)};
        std::getline(ss, value, ',');
        auto y{std::stod(value)};
        std::getline(ss, value, ',');
        auto z{std::stod(value)};
        std::getline(ss, value, ',');
        auto mass{std::stod(value)};
        std::getline(ss, value, ',');

        bodies.emplace_back(x, y, z, mass);
    }

    std::cout << "Loaded " << bodies.size() << " elements.\n";

    return bodies;
}

void saveBodiesCsv(std::vector<Body> bodies, std::filesystem::path path)
{
    std::ofstream os{path.concat(".csv"), std::ios::out | std::ios::trunc};
    os << "x_position,y_position,z_position,x_velocity,y_velocity,z_velocity,x_acceleration,y_acceleration,z_"
          "acceleration,mass\n";

    for (std::size_t i = 0; i < bodies.size(); i++)
    {
        os << std::fixed << std::setprecision(std::numeric_limits<double>::max_digits10) << bodies[i].position.x()
           << "," << bodies[i].position.y() << "," << bodies[i].position.z() << "," << bodies[i].velocity.x() << ","
           << bodies[i].velocity.y() << "," << bodies[i].velocity.z() << "," << bodies[i].acceleration.x() << ","
           << bodies[i].acceleration.y() << "," << bodies[i].acceleration.z() << "," << bodies[i].mass << '\n';
    }
}