def fractional_knapsack(weights, values, capacity):
    n = len(weights)
    ratio = [values[i] / weights[i] for i in range(n)]
    index = list(range(n))
    index.sort(key=lambda i: ratio[i], reverse=True)
    max_value = 0
    fractions = [0] * n
    for i in index:
        if weights[i] <= capacity:
            fractions[i] = 1
            max_value += values[i]
            capacity -= weights[i]
        else:
            fractions[i] = capacity / weights[i]
            max_value += values[i] * capacity / weights[i]
            break
    return max_value, fractions

if __name__ == "__main__":
    # Input from user
    weights = list(map(int, input("Enter the weights of the items: ").split()))
    values = list(map(int, input("Enter the values of the items: ").split()))
    capacity = int(input("Enter the capacity of the knapsack: "))

    # Function call
    max_value, fractions = fractional_knapsack(weights, values, capacity)
    print("The maximum value that can be obtained is:", max_value)
    print("The fractions of the items to be included are:", fractions)
