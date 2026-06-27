/*
======================== BIT TRICKS ========================

Set i-th bit
x |= (1LL << i);

Clear i-th bit
x &= ~(1LL << i);

Toggle i-th bit
x ^= (1LL << i);

Check i-th bit
(x >> i) & 1

Lowest set bit
x & -x

Remove lowest set bit
x &= (x - 1);

Is power of two
x && !(x & (x - 1))

Count set bits
__builtin_popcount(x)
__builtin_popcountll(x)

Leading zeros
__builtin_clz(x)
__builtin_clzll(x)

Trailing zeros
__builtin_ctz(x)
__builtin_ctzll(x)

Parity
__builtin_parity(x)

Highest set bit
63 - __builtin_clzll(x)

Lowest set bit index
__builtin_ctzll(x)

Next subset
subset = (subset - 1) & mask;

Iterate all subsets
for(int sub = mask; ; sub = (sub - 1) & mask){
    ...
    if(sub == 0) break;
}

Iterate all masks
for(int mask = 0; mask < (1 << n); mask++)

Enumerate set bits
for(int x = mask; x; x &= x - 1){
    int bit = __builtin_ctz(x);
}

============================================================
*/