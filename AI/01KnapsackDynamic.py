def knapsack_dynamic(weights, values, capacity):
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        for w in range(capacity + 1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif weights[i - 1] <= w:
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]
    max_value = dp[n][capacity]
    max_combination = []
    w = capacity
    for i in range(n, 0, -1):
        if max_value <= 0:
            break
        if max_value == dp[i - 1][w]:
            continue
        else:
            max_combination.append(i - 1)
            max_value -= values[i - 1]
            w -= weights[i - 1]
    return max_value, max_combination

if __name__ == "__main__":
    # Input from user
    weights = list(map(int, input("Enter the weights of the items: ").split()))
    values = list(map(int, input("Enter the values of the items: ").split()))
    capacity = int(input("Enter the capacity of the knapsack: "))

    # Function call
    max_value, max_combination = knapsack_dynamic(weights, values, capacity)
    print("The maximum value that can be obtained is:", max_value)
    print("The items to be included are:", max_combination)
