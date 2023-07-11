#pragma once

#include <vector>

#include "ForceEngine.hpp"

class Body;

class Integrator
{
  public:
    virtual void initialize(std::vector<Body> &bodies, const ForceEngine &forceEngine) = 0;
    virtual void operator()(std::vector<Body> &bodies, const double deltaTime, const ForceEngine &forceEngine) = 0;

    virtual ~Integrator()
    {
    }
};
