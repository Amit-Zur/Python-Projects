## Explanation

### 1. Function Declaration:
- **Syntax:** `float celsius_to_fahrenheit(float celsius);`
- The function declaration, also known as the prototype, tells the compiler about the function's name, return type, and parameters. This allows the function to be called before its definition. In this case, the function `celsius_to_fahrenheit` takes a `float` (Celsius temperature) as an argument and returns a `float` (Fahrenheit temperature).

### 2. Function Definition:
- **Syntax:** `float celsius_to_fahrenheit(float celsius)`
- The function definition contains the actual logic to perform the conversion. It multiplies the Celsius temperature by 1.8 and then adds 32 to convert it to Fahrenheit. The result is returned as a `float`.

### 3. Function Call:
- **Syntax:** `float fahrenheit = celsius_to_fahrenheit(temperature);`
- In the `main()` function, after prompting the user to input a temperature in Celsius, the program calls the `celsius_to_fahrenheit` function, passing the user's input as an argument. The function returns the equivalent temperature in Fahrenheit, which is then stored in the `fahrenheit` variable.
- Finally, the program prints the converted temperature.

### Example Output:

When you run this program, it prompts you for a Celsius temperature, converts it to Fahrenheit using the function, and displays the result. For example:

```
Input temperature in degree Celsius: 25
Equivalent temperature in degree Fahrenheit is: 77.000000
```

### Summary:
- **Function Creation**: Functions in C are created with a return type, a name, and parameters (optional). The function is then defined with logic, and it can be called from `main()` or other functions.
- **Modularity**: This approach makes your code more modular and reusable. The conversion logic is now encapsulated in the `celsius_to_fahrenheit` function, which can be called anywhere in your program.
