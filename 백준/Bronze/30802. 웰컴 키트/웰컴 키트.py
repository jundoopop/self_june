import math

# T-shirts sizes : S, M, L, XL, XXL, XXXL
# Bundles have same sized t-shirts

# S + M + L + XL + XXL + XXXL = N

num_of_participants = int(input())

# s, m, l, xl, xxl, xxxl
shirts_demand_by_size = map(int, input().split())
shirts_bundle_size, pens_bundle_size = map(int, input().split())

minimum_number_of_bundles = 0

# Calculate number of shirts bundles for each size
for num in shirts_demand_by_size:
    minimum_number_of_bundles += math.ceil(num / shirts_bundle_size)

# Print the minimum number of shirts bundles
print(int(minimum_number_of_bundles))

# Calculate number of pens bundles and one by one pens
print(
    f"{num_of_participants // pens_bundle_size} "
    f"{num_of_participants % pens_bundle_size}"
)
