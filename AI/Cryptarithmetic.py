import re
def solve(q):
    try:
        n = next(i for i in q if i.isalpha())  # Check if q has alphabetic characters
    except StopIteration:
        return q if eval(re.sub(r'(^|[^0-9])0+([1-9]+)', r'\1\2', q)) else False
    else:
        for i in (str(i) for i in range(10) if str(i) not in q):
            r = solve(q.replace(n, str(i)))  # Replace character with number
            if r:
                return r
        return False
if __name__ == "__main__":
    query = input("Enter the cryptarithmetic puzzle (e.g., 'SEND + MORE == MONEY'):")
    # Correcting the puzzle format by replacing '=' with '=='
    query = query.replace('=', '==')
    r = solve(query)
    print(r) if r else print("No solution found.")
