## Explanation of the `while` Loop in `credit.c`

The `while` loop is a crucial part of the credit card validation logic. Here's a breakdown of what each part of the loop does:

### `while (card_number > 0)`
- This loop iterates through each digit of the `card_number` starting from the last digit (the rightmost digit).
- The loop continues as long as there are digits left in `card_number`.

### `int digit = card_number % 10;`
- **Extract the Last Digit**: `card_number % 10` gives us the last digit of the current `card_number`. For example, if `card_number` is `1234`, `digit` would be `4`.

### `if (count % 2 == 0)`
- **Check Position**: This checks if the current digit's position (from the end) is even.
- If the position is even, the digit is directly added to the `sum`.

### `sum += digit;`
- **Add Digit to Sum**: If the current digit’s position is even, it’s simply added to the `sum`.

### `else`
- If the position is odd (i.e., every other digit starting from the second-to-last), the digit is multiplied by 2.

### `int product = digit * 2;`
- **Multiply by 2**: The digit is multiplied by 2 as per Luhn’s algorithm.

### `sum += product / 10 + product % 10;`
- **Add Both Digits of Product**: If the product is a two-digit number, this line adds both digits of the product to the `sum`.
  - For example, if `product` is `14`, `product / 10` gives `1` (the tens place), and `product % 10` gives `4` (the units place). Both `1` and `4` are added to `sum`.

### `if (card_number < 100 && card_number >= 10)`
- **Track the Second Digit**: This condition checks if we are down to the last two digits of the `card_number`.
- If true, the current digit is stored as `second_digit`.

### `else if (card_number < 10)`
- **Track the First Digit**: This condition checks if we are down to the last digit of the `card_number`.
- If true, the current digit is stored as `first_digit`.

### `card_number /= 10;`
- **Remove the Last Digit**: This operation effectively shifts the number to the right by one digit (i.e., it removes the last digit).
  - For example, if `card_number` was `1234`, after this operation it becomes `123`.

### `count++;`
- **Increment Digit Count**: This increments the `count` variable to keep track of how many digits have been processed.

### Summary
- The loop continues until all digits of the `card_number` have been processed.
- The `sum` is calculated according to Luhn’s algorithm, and the `first_digit` and `second_digit` are stored for later use in determining the card type.

This loop is essential for validating the credit card number and determining its type (AMEX, MASTERCARD, VISA) based on its structure and the Luhn checksum.
