#include <iostream>
#include <cmath>
/* Find a root of equation x^3-6x^2+11x-6=0 at the interval [-10,10] by the following method:
    - Check the signs of the function at the borders of the interval and its middle
    - Modify the interval such that the function has different signs at borders (middle becomes one of the new borders)
    - Repeat until the interval is smaller than 10^(-9) */

int main(){
  double low, high, mid;
  high = 10;
  low = -10;
  double f_low, f_high, f_mid;
  while (high - low > pow(10, -9)){
    mid = (high + low) / 2;

    // Evaluate function at midpoint, upper and lower extreme.
    f_mid = pow(mid, 3) - 6 * std::pow(mid, 2) + 11 * mid - 6;
    f_high = pow(high, 3) - 6 * std::pow(high, 2) + 11 * high - 6;

    // Change the interval accordingly
    if (f_mid * f_high > 0){
      high = mid;
    }else{
      low = mid;

    }

  }
  std::cout<<"The solution lies in the interval ["<<low<<", "<<high<<"]."<<std::endl;
}
