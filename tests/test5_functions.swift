// Test 5: Functions (return values, parameters, named parameters, Void return type)

func add(a: Int, b: Int) -> Int {
    return a + b
}

func multiply(x: Int, y: Int) -> Int {
    let result = x * y
    return result
}

func greet(name: String) -> Void {
    let greeting = "Welcome, " + name
    print(greeting)
}

func sayHello() {
    print("Hello from Void function!")
}

let sum = add(a: 10, b: 20)
let product = multiply(x: 5, y: 6)
greet(name: "Alice")
sayHello()

print(sum)
print(product)
