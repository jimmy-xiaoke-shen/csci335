"""
1 + 2 + 3 +... + n = ?
"""
def bottom_up_sum(n):
    """
    O(n)
    O(1)
    """
    return sum(range(n + 1))

def top_down_n_sum(n):
    """
    This code is bad. For example when n is a super large number.
    O(n)
    O(n)
    """
    # base case divide and conquer
    if n == 0:
        return 0
    return n + top_down_n_sum(n - 1)

if __name__ == "__main__":
    n = int(input("plese input a positive number n:"))
    print(bottom_up_sum(n))
    print(top_down_n_sum(n))
