// Test 2: Variable Declarations (let immutable vs var mutable)

// Immutable declarations
let maxScore = 100
let appName: String = "SwiftCompiler"

// Mutable declarations
var currentScore = 0
var status = "Playing"

// Valid reassignments to mutable variables
currentScore = 10
currentScore = currentScore + 15
status = "Completed"

print(appName)
print(currentScore)
print(status)
