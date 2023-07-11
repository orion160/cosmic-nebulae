#pragma once

#include <vector>

class ForceEngine;

class Body;

class Integrator
{
  public:
    Integrator(const ForceEngine &forceEngine);

    virtual void operator()(std::vector<Body> &bodies, const double deltaTime) = 0;

  protected:
    const ForceEngine &forceEngine;
};
