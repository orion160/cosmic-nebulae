#include <iostream>
#include <memory>
#include <vector>

#include <Eigen/Core>

#include "BasicForceEngine.hpp"
#include "Body.hpp"
#include "Leapfrog.hpp"
#include "Simulator.hpp"

int main(int argc, char **argv)
{
    std::vector<Body> bodies{Body{.position = Eigen::Vector3d{0.0, 0.0, 0.0},
                                  .velocity = Eigen::Vector3d::Zero(),
                                  .acceleration = Eigen::Vector3d::Zero(),
                                  .mass = 1e12},
                             Body{.position = Eigen::Vector3d{10.0, 0.0, 0.0},
                                  .velocity = Eigen::Vector3d::Zero(),
                                  .acceleration = Eigen::Vector3d::Zero(),
                                  .mass = 1e11},
                             Body{.position = Eigen::Vector3d{19.0, 0.0, 0.0},
                                  .velocity = Eigen::Vector3d::Zero(),
                                  .acceleration = Eigen::Vector3d::Zero(),
                                  .mass = 5e11}};

    Simulator simulator{std::make_unique<BasicForceEngine>(), std::make_unique<LeapfrogIntegrator>(),
                        std::make_shared<std::vector<Body>>(bodies)};

    std::cout << "Initial state:\n";
    for (auto &body : *simulator.getBodies())
    {
        std::cout << body << '\n';
    }

    std::cout << "After the initialization:\n";
    simulator.initialize();
    for (auto &body : *simulator.getBodies())
    {
        std::cout << body << '\n';
    }

    std::cout << "After the simulation:\n";
    simulator(1.0);
    for (auto &body : *simulator.getBodies())
    {
        std::cout << body << '\n';
    }

    return 0;
}