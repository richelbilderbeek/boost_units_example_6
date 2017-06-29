#include <iostream>
#include <iomanip>

#include <boost/math/constants/constants.hpp>
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/units/systems/si/plane_angle.hpp>
#include <boost/units/systems/si/io.hpp>

int main()
{
  typedef boost::units::quantity<boost::units::si::plane_angle> Angle;
  using boost::units::si::radians;

  const double pi = boost::math::constants::pi<double>();
  const Angle delta(2.0 * pi * radians / 16.0);
  const Angle j(2.0 * pi * radians);
  std::cout << std::setprecision(20);
  for (Angle i(0.0 * pi * radians); i<j; i+=delta)
  {
    std::cout << "sin(" << i << ") = " << std::sin(i.value()) << '\n';
  }

  //Converting between radians and degrees
  using boost::units::degree::degree;
  {
    const Angle r(2.0 * boost::units::si::radians);
    std::cout
      << "r is " << r << ", and "
      << (r * degree / radians).value() << " degrees" //Gives incorrect answer
    ;
  }
}
