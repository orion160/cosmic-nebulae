#pragma once

#include <memory>
#include <vector>

class Body;
class Integrator;
class ForceEngine;

class Simulator
{
  public:
    Simulator(std::unique_ptr<ForceEngine> forceEngine, std::unique_ptr<Integrator> integrator,
              std::shared_ptr<std::vector<Body>> bodies);

    void initialize();
    void operator()(double deltaTime);

    std::shared_ptr<std::vector<Body>> getBodies() const;

  private:
    std::unique_ptr<ForceEngine> forceEngine;
    std::unique_ptr<Integrator> integrator;
    std::shared_ptr<std::vector<Body>> bodies;
};
