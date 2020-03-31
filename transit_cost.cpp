#include <iostream> // for std::cout
#include <string>
#include <vector>

std::vector<double> fares = {2.75, 32.00, 121.00};
std::vector<std::string> fare_options = {"pay per ride", "7-day unlimited", "30-day unlimited"};

std::vector<double> cost_per_ride(int days, int rides) {

  double ppr_price = 2.75;
  double unlimited7_price = (days / 7) * 32.00;
  if (days % 7 > 0)
  {
    unlimited7_price += 32.00;
  }

  unlimited7_price /= rides;
  std::cout << unlimited7_price;

  double unlimited30_price = 121.00 / rides;

  std::vector<double> ride_prices = { ppr_price,
                                      unlimited7_price,
                                      unlimited30_price };
  return ride_prices;
}

void get_best_fare(int days, int rides) {
  std::vector<double> ride_prices = cost_per_ride(days, rides);

  double minimum = ride_prices[0];
  int min_index = 0;

  for (int i = 0; i < ride_prices.size(); i++) {
    if(ride_prices[i] < minimum) {
      minimum = ride_prices[i];
      min_index = i;
    }
  }
  std::cout << "The cheapest option is " << fare_options[min_index] <<
  "\n";

  std::cout <<"The cost per ride is $" << minimum << "\n";
}

int main() {
  int days, rides;
  std::cout << "Welcome to the MTA Best Fare Calculator\n";
  std::cout << "How many days will you be using your Metro Card\n";
  std::cin >> days;
  std::cout << "How many times do you expect to use the subway?\n";
  std::cin >> rides;

  get_best_fare(days, rides);
  return 0;
}

