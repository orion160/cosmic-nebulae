#pragma once

#include "ForceEngine.hpp"

class BasicForceEngine : public ForceEngine
{
  public:
    std::vector<Eigen::Vector3d> operator()(std::vector<Body> &bodies) const override;

  private:
    Eigen::Vector3d bodyBodyInteraction(Body &current, Body &other) const noexcept override;
};
