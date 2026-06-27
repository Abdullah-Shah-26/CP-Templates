/*
======================== STL REFERENCE ========================

---------------- lower_bound ----------------
// First element >= x
auto it = lower_bound(all(v), x);

if(it != v.end()) {
    int idx = it - v.begin();
    ll val = *it;
}

---------------- upper_bound ----------------
// First element > x
auto it = upper_bound(all(v), x);

---------------- equal_range ----------------
// {lower_bound, upper_bound}
auto [l, r] = equal_range(all(v), x);

---------------- binary_search ----------------
// Returns bool
bool ok = binary_search(all(v), x);

---------------- unique ----------------
// Removes consecutive duplicates
sort(all(v));
v.erase(unique(all(v)), v.end());

---------------- nth_element ----------------
// k-th smallest at index k
nth_element(begin(v), begin(v)+k, end(v));

// v[k] is correct
// left <= v[k] <= right

---------------- partial_sort ----------------
// First k elements sorted
partial_sort(begin(v), begin(v)+k, end(v));

---------------- rotate ----------------
// Left rotate
rotate(begin(v), begin(v)+k, end(v));

// Right rotate
rotate(begin(v), end(v)-k, end(v));

---------------- iota ----------------
// Fill with consecutive values
iota(all(v), 0);      // 0 1 2 3 ...
iota(all(v), 1);      // 1 2 3 4 ...

---------------- accumulate ----------------
// Sum
ll sum = accumulate(all(v), 0LL);

---------------- partial_sum ----------------
// Prefix sums
vector<ll> pref(v.size());
partial_sum(all(v), pref.begin());

---------------- adjacent_difference ----------------
// Difference array
vector<ll> diff(v.size());
adjacent_difference(all(v), diff.begin());

---------------- min/max ----------------
auto mn = *min_element(all(v));
auto mx = *max_element(all(v));

auto [mnIt, mxIt] = minmax_element(all(v));

---------------- remove ----------------
// Remove value x
v.erase(remove(all(v), x), v.end());

---------------- remove_if ----------------
v.erase(remove_if(all(v),
    [](int x){ return x & 1; }),
    v.end());

---------------- merge ----------------
// Both arrays sorted
merge(all(a), all(b), back_inserter(c));

---------------- set algorithms ----------------
// Both arrays sorted
set_union(...)
set_intersection(...)
set_difference(...)
set_symmetric_difference(...)

---------------- next_permutation ----------------
while(next_permutation(all(v))) {
}

---------------- prev_permutation ----------------
while(prev_permutation(all(v))) {
}

===============================================================
*/