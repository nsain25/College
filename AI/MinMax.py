def find_min_max():
  """Prompts the user for multiple numbers and returns the minimum and maximum."""
  numbers = []
  while True:
    number_str = input("Enter a number (or 'q' to quit): ")
    if number_str.lower() == 'q':
      break
    try:
      number = float(number_str)
      numbers.append(number)
    except ValueError:
      print("Invalid input. Please enter a number.")

  if not numbers:
    print("No numbers entered.")
    return None, None

  min_value = min(numbers)
  max_value = max(numbers)
  return min_value, max_value

# Get numbers from user
min_value, max_value = find_min_max()

# Print results (handle case where no numbers were entered)
if min_value is not None:
  print("Minimum:", min_value)
  print("Maximum:", max_value)
