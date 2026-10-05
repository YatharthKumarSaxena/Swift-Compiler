// Test 3: Control Flow (if, else, switch with case, default)

let score = 85

// if-else construct
if score >= 90 {
    print("Grade: A")
} else {
    if score >= 80 {
        print("Grade: B")
    } else {
        print("Grade: C or below")
    }
}

// switch construct with case and default
let code = 2
switch code {
    case 1:
        print("Option 1 selected")
    case 2:
        print("Option 2 selected")
    case 3:
        print("Option 3 selected")
    default:
        print("Default fallback option")
}
