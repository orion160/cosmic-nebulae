#pragma once

#include <vector>

#include <Eigen/Core>

class Body;

class ForceEngine
{
  public:
    static inline constexpr double G = 6.67430e-11;
    static inline constexpr double Epsilon2 = 1e-3;

    virtual std::vector<Eigen::Vector3d> operator()(std::vector<Body> &bodies) const = 0;

  private:
    virtual Eigen::Vector3d bodyBodyInteraction(Body &current, Body &other) const = 0;
};
