// Test 8: Semantic Error Diagnostics

// 1. Immutability Violation: Reassignment to let
let maxLimit = 100
maxLimit = 200

// 2. Type Mismatch in Assignment
var age: Int = 25
age = "Twenty Five"

// 3. Undeclared Identifier
print(undeclaredVariable)

// 4. Duplicate Declaration in same scope
var value = 10
var value = 20

// 5. Non-boolean condition in if statement
let count = 5
if count {
    print("Invalid condition")
}

// 6. Subscripting a non-array or invalid index type
let flag = true
var items = [1, 2, 3]
let invalidItem = items["first"]

// 7. Non-existent struct member and mutating let struct
struct Box {
    var width: Int
}
let b = Box(width: 50)
b.width = 100
print(b.height)
