#include <iostream>
#include <cstdlib>

// A naive and a fast (using Euclid method) algorithms 
// to find the least common multiple of two integers

using namespace std;

long long lcm_naive(unsigned long long a, unsigned long long b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

unsigned long long gcd_euclid(unsigned long long a, unsigned long long b){
  unsigned long long m, n;

  if (a < b) gcd_euclid(b, a);
  if(b==0) return a;

  unsigned long long r = a % b;
  return gcd_euclid(b, r); 
}

unsigned long long lcm_fast(unsigned long long a, unsigned long long b){
  return (unsigned long long) b / gcd_euclid(a, b) * a;
}

int main() {
  unsigned long long a, b;
  cin >> a >> b;
  cout << lcm_fast(a, b) << endl;  
  return 0;
}
