// Test 9: Lexical and Syntactic Error Diagnostics

// 1. Invalid Character (e.g. # or @ or $)
var #badIdentifier = 10

// 2. Unterminated String
let unclosed = "This string has no closing quote

// 3. Unterminated multi-line comment
/* This comment is never closed
var x = 5
