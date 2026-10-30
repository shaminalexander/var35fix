/***************************************************
 * Автор:     Шамин А.С.                           *
 * Задание:   Циклы с предусловием и постусловием  *
 * Вариант:   35                                   *
 ***************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double thickness;
  double firstIndex;
  double secondIndex;

  cout << "Enter layer thickness, first index and second index: ";
  if (!(cin >> thickness >> firstIndex >> secondIndex)) {
    cout << "Invalid input.";
    return 1;
  }

  if (thickness <= 0.0 || firstIndex <= 0.0 || secondIndex <= 0.0 || firstIndex > secondIndex) {
    cout << "Invalid input data.";
    return 1;
  }

  const double speedOfLight = 300000000.0;
  const double pi = 3.1415926535;
  const double degreesInHalfCircle = 180.0;
  const double nanosecondsPerSecond = 1000000000.0;
  const double firstStep = 5.0;
  const double secondStep = 10.0;
  const double changeAngle = 20.0;
  const double finishAngle = 60.0;

  double velocity;
  double angle;
  double angleInRadians;
  double refractionAngle;
  double travelTime;
  int stepIndex;
  int rowNumber;

  velocity = speedOfLight / secondIndex;

  cout << "Step  Angle (degrees)  Refraction angle (degrees)  Time (ns)\n";

  stepIndex = 0;
  rowNumber = 1;
  do {
    angle = stepIndex * firstStep;
    angleInRadians = angle * pi / degreesInHalfCircle;
    refractionAngle = asin(firstIndex / secondIndex * sin(angleInRadians));
    travelTime = thickness / (velocity * cos(refractionAngle));

    cout << rowNumber << "  " << angle << "  "
         << refractionAngle * degreesInHalfCircle / pi << "  "
         << travelTime * nanosecondsPerSecond << '\n';

    ++stepIndex;
    ++rowNumber;
  } while (stepIndex * firstStep <= changeAngle);

  stepIndex = 1;
  while (changeAngle + stepIndex * secondStep <= finishAngle) {
    angle = changeAngle + stepIndex * secondStep;
    angleInRadians = angle * pi / degreesInHalfCircle;
    refractionAngle = asin(firstIndex / secondIndex * sin(angleInRadians));
    travelTime = thickness / (velocity * cos(refractionAngle));

    cout << rowNumber << "  " << angle << "  "
         << refractionAngle * degreesInHalfCircle / pi << "  "
         << travelTime * nanosecondsPerSecond << '\n';

    ++stepIndex;
    ++rowNumber;
  }

  return 0;
}
