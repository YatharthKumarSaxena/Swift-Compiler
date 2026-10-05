// Swift Subset Compiler - All-in-One Comprehensive Showcase
// Covers Specifications 1 through 9

// 1. Primitive Types & 2. Type Inference & 3. Declarations (let/var)
let intVal = 42
let doubleVal = 3.14
let boolVal = true
let charVal = 'S'
let strVal = "Swift"
var mutableCount: Int = 10
mutableCount = mutableCount + 5

// 4. Operators: Arithmetic, Relational, Logical, String Concatenation
let sum = intVal + mutableCount
let isOk = (sum > 50) && boolVal
let fullGreeting = strVal + " Compiler"

// 5. Control Flow: if-else, switch-case-default
if isOk {
    print("Check Passed")
} else {
    print("Check Failed")
}

let choice = 1
switch choice {
    case 1:
        print("Selected 1")
    default:
        print("Default Selected")
}

// 6. Loops: while, repeat-while, for-in
var w = 0
while w < 2 {
    w = w + 1
}

var r = 1
repeat {
    r = r * 2
} while r < 4

for i in 1...3 {
    print(i)
}

// 7. Functions: Named parameters, return types, Void
func addNumbers(a: Int, b: Int) -> Int {
    return a + b
}

func sayHi(target: String) -> Void {
    print("Hi, " + target)
}

let res = addNumbers(a: 20, b: 30)
sayHi(target: "Viva")

// 8. Arrays: 1D fixed size, subscript notation
var arr = [100, 200, 300]
let elem = arr[0]
arr[1] = 999
print(arr[1])

// 9. User-Defined Types: struct (Exact Assignment Spec)
struct Point {
    var x: Int
    var y: Int
}
var p = Point(x: 3, y: 4)
print(p.x)
p.x = 10
print(p.x)
