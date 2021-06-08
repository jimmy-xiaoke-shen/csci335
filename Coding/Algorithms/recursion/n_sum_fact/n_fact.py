"""
1 * 2 * 3 *... * n = ?
"""


def bottom_up_fact(n):
    ret = 1
    for i in range(1, n + 1):
        ret *= i
    return ret


def top_down_n_fact(n):
    """
    This time it is good
    """
    # base case divide and conquer
    if n == 0:
        return 1
    return n * top_down_n_fact(n - 1)


if __name__ == "__main__":
    n = int(input("plese input a positive number n:"))
    print(bottom_up_fact(n))
    print(top_down_n_fact(n))
