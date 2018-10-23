#include <iostream>

/// Calculate the greatest common devisor of two values.
/// @param[in] a The first value, must be positive number.
/// @param[in] a The second value, must be positive number.
/// @return The gcd of a and b.
int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

/// Calculate the least common multiplier of two values.
/// @param[in] a The first value, must be positive number.
/// @param[in] a The second value, must be positive number.
/// @return The lcm of a and b.
int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
	std::cout << "GCD of 1 and 10 is: " << gcd(1, 10) << '\n';
	std::cout << "GCD of 5 and 1 is: " << gcd(5, 1) << '\n';
	std::cout << "GCD of 15 and 12 is: " << gcd(15, 12) << '\n';
	std::cout << "GCD of 24 and 56 is: " << gcd(24, 56) << '\n';

	std::cout << "LCM of 1 and 10 is: " << lcm(1, 10) << '\n';
	std::cout << "LCM of 5 and 1 is: " << lcm(5, 1) << '\n';
	std::cout << "LCM of 15 and 12 is: " << lcm(15, 12) << '\n';
	std::cout << "LCM of 24 and 56 is: " << lcm(24, 56) << '\n';

	return 0;
}