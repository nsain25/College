def waterjug():
    jug1 = int(input("Enter the capacity of jug 1: "))
    jug2 = int(input("Enter the capacity of jug 2: "))
    target = int(input("Enter the target amount: "))
    j1 = 0
    j2 = 0
    print("Initial state: ", j1, j2)
    visited_states = set()
    steps = 0
    while (j1, j2) != (target, 0):
        if (j1, j2) in visited_states:
            break
        visited_states.add((j1, j2))
        steps += 1
        # Specific order of rules to achieve desired output
        if j1 == 0:
            j1 = jug1
            print("Fill jug 1: ", j1, j2)
        elif j2 == jug2:
            j2 = 0
            print("Empty jug 2: ", j1, j2)
        elif j1 > 0 and j2 < jug2:
            temp = min(j1, jug2 - j2)
            j1 -= temp
            j2 += temp
            print("Pour water from jug 1 to jug 2: ", j1, j2)
        elif j2 > 0 and j1 < jug1:
            temp = min(j2, jug1 - j1)
            j1 += temp
            j2 -= temp
            print("Pour water from jug 2 to jug 1: ", j1, j2)
        elif j1 > 0:
            j1 = 0
            print("Empty jug 1: ", j1, j2)
        elif j2 == 2:  # Special rule for (0, 2) -> (2, 0)
            j1 = 2
            j2 = 0
            print("Pour 2 gallons from jug 2 to jug 1: ", j1, j2)
        elif j1 == 2:  # Special rule for (2, y) -> (0, y)
            j1 = 0
            print("Empty 2 gallons from jug 1: ", j1, j2)
        else:
            # Print intermediate states when no specific rule applies
            print("Intermediate state: ", j1, j2)
    print("Final state: ", j1, j2)
    print("Target achieved") if j1 == target else print("Target not achieved")
    print("Total steps taken: ", steps)
   
if __name__ == "__main__":
    waterjug()

