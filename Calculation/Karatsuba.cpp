#include <iostream>
#include <math.h>

size_t karatsuba(size_t num1, size_t num2)
{
  if (num1 < 10 || num2 < 10)
    return num1 * num2;

  size_t n = 1;
  while (num1 > 10)
  {
    num1 /= 10;
    n++;
  }

  size_t a = num1;
  size_t c = num2;
  size_t i = 1;
  while (i != n / 2)
  {
    a /= 10;
    c /= 10;
    ++i;
  }

  size_t b = num1 - a;
  size_t d = num2 - c;

  size_t ac = pow(10, n) * karatsuba(a, c);
  size_t bd = karatsuba(b, d);
  size_t ad_bc = pow(10, n / 2) * karatsuba(a + b, c + d) - ac - bd;

  return ac + bd + ad_bc;
}

int main(int argc, char const *argv[])
{
  std::cout << karatsuba(100, 20) << std::endl;
  return 0;
}
