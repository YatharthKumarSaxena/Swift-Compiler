// Test 7: User-Defined Types (struct)
// Assignment Objective Example Requirement 9

struct Point {
    var x: Int
    var y: Int
}

var p = Point(x: 3, y: 4)
print(p.x)
print(p.y)

// Field mutation on mutable struct
p.x = 10
p.y = 20
print(p.x)
print(p.y)

// Immutable struct
let origin = Point(x: 0, y: 0)
print(origin.x)
print(origin.y)
