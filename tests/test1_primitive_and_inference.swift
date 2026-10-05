// Test 1: Primitive Types, Type Inference, Operators & String Concatenation

// Type Inference
let anInt = 42
let aDouble = 3.14159
let aBool = true
let aChar = 'S'
let aString = "Hello Swift"

// Explicit Type Annotations
var counter: Int = 10
var ratio: Double = 0.75
var active: Bool = false
var letter: Character = 'Z'
var greeting: String = "Hello"

// Arithmetic Operators
var sum = anInt + counter
var diff = anInt - counter
var prod = counter * 5
var quot = anInt / 2
var rem = anInt % 10

// String Concatenation using '+'
let part1 = "Hello, "
let part2 = "World!"
let message = part1 + part2

// Relational and Logical Operators
let isGreater = sum > diff
let isEqual = counter == 10
let complexCondition = (isGreater && isEqual) || !active

print(sum)
print(message)
print(complexCondition)
