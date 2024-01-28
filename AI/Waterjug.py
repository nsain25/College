def waterjug():
    jug1 = int(input("Enter the capacity of jug 1: "))
    jug2 = int(input("Enter the capacity of jug 2: "))
    target = int(input("Enter the target amount: "))
    j1 = 0
    j2 = 0
    print("Initial state: ", j1, j2)

    visited_states = set()

    while (j1, j2) != (target, target):
        if (j1, j2) in visited_states:
            # Break the loop if the same state has been visited before
            break

        visited_states.add((j1, j2))

        if j1 == 0:
            j1 = jug1
            print("Fill jug 1: ", j1, j2)
        elif j2 == jug2:
            j2 = 0
            print("Empty jug 2: ", j1, j2)
        elif j1 != 0 and j2 != jug2:
            temp = min(j1, jug2 - j2)
            j1 -= temp
            j2 += temp
            print("Pour water from jug 1 to jug 2: ", j1, j2)
        elif j2 != 0 and j1 != jug1:
            temp = min(j2, jug1 - j1)
            j1 += temp
            j2 -= temp
            print("Pour water from jug 2 to jug 1: ", j1, j2)

    print("Final state: ", j1, j2)
    print("Target achieved")

if __name__ == "__main__":
    waterjug()
