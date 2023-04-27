import random

nums = [random.randint(0, 9999) for _ in range(100000)]

with open("data.txt", "w") as f:
    f.write(",".join(str(num) for num in nums))
