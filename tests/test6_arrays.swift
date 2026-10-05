// Test 6: Arrays (1D arrays of fixed size, element access, subscript assignment)

var numbers = [10, 20, 30, 40, 50]

// Read array elements
let first = numbers[0]
let second = numbers[1]
print(first)
print(second)

// Modify array element
numbers[2] = 99
let third = numbers[2]
print(third)

// Array element with expression index
let idx = 3
let fourth = numbers[idx]
print(fourth)

// Iterating over array using for-in loop
for val in numbers {
    print(val)
}
