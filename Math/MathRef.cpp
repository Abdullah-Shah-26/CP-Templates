/*
======================== MATH REFERENCE ========================

GCD
gcd(a, b)

LCM
lcm(a, b) = a / gcd(a, b) * b

Extended GCD
ax + by = gcd(a, b)

Mod Properties
(a + b) % MOD
(a - b + MOD) % MOD
(a * b) % MOD
(a / b) % MOD = a * modInverse(b) % MOD

Binary Exponentiation
binExpo(a, b)

Mod Inverse (MOD Prime)
binExpo(a, MOD - 2)

nCr
fact[n] * invFact[r] % MOD * invFact[n - r] % MOD

Permutation
nPr = fact[n] * invFact[n - r] % MOD

Arithmetic Progression
Sum = n * (2a + (n - 1)d) / 2

Geometric Progression
Sum = a * (r^n - 1) / (r - 1)

Factorials
0! = 1

Prime Factorization
n = Π(p^freq)

Number of Divisors
Π(freq + 1)

Sum of Divisors
Π((p^(freq + 1) - 1) / (p - 1))

Euler Totient
φ(n) = n * Π(1 - 1/p)

Catalan Number
C(2n, n) / (n + 1)

Derangement
!n = (n - 1)(!(n - 1) + !(n - 2))

Pigeonhole Principle
n + 1 objects into n boxes => one box has >= 2

Inclusion-Exclusion
|A ∪ B| = |A| + |B| - |A ∩ B|

Expected Value
E[X] = Σ(x * P(x))

XOR Facts
a ^ a = 0
a ^ 0 = a
0 ^ a = a
1 ^ 2 ^ ... ^ n =
n % 4 == 0 -> n
n % 4 == 1 -> 1
n % 4 == 2 -> n + 1
n % 4 == 3 -> 0

Ceil Division
(a + b - 1) / b          // b > 0

Floor Division
a / b

Overflow-safe Mid
l + (r - l) / 2

Integer log2
__lg(x)

Power of Two
x && !(x & (x - 1))

Next Power of Two
1LL << (64 - __builtin_clzll(x - 1))

===============================================================
*/