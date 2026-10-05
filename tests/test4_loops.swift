// Test 4: Loops (while, repeat-while, for-in)

// while loop
var count = 0
while count < 3 {
    print(count)
    count = count + 1
}

// repeat-while loop
var n = 1
repeat {
    print(n)
    n = n * 2
} while n < 8

// for-in loop with range
for i in 1...5 {
    print(i)
}
