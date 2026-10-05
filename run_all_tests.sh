#!/usr/bin/env bash
set -e

echo "================================================================================"
echo "          SWIFT SUBSET COMPILER - AUTOMATED TEST SUITE RUNNER                   "
echo "================================================================================"

# Build compiler
echo "[1/3] Building compiler in final-compiler/..."
cd final-compiler
make clean
make
cd ..

OUTPUT_FILE="COMPILER_EXECUTION_RESULTS.txt"
echo "================================================================================" > "$OUTPUT_FILE"
echo "        SWIFT SUBSET COMPILER - COMPLETE EXECUTION & TEST RESULTS               " >> "$OUTPUT_FILE"
echo "================================================================================" >> "$OUTPUT_FILE"
echo "Generated on: $(date)" >> "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"

run_test() {
    local test_name="$1"
    local test_path="$2"
    local expect_fail="$3"

    echo "--------------------------------------------------------------------------------" >> "$OUTPUT_FILE"
    echo "TEST: $test_name ($test_path)" >> "$OUTPUT_FILE"
    echo "--------------------------------------------------------------------------------" >> "$OUTPUT_FILE"
    echo "Source Code:" >> "$OUTPUT_FILE"
    cat "$test_path" >> "$OUTPUT_FILE"
    echo "" >> "$OUTPUT_FILE"
    echo "Compiler Execution Output:" >> "$OUTPUT_FILE"

    set +e
    ./final-compiler/swiftc_subset "$test_path" >> "$OUTPUT_FILE" 2>&1
    local exit_code=$?
    set -e

    if [ "$expect_fail" = "1" ]; then
        if [ $exit_code -ne 0 ]; then
            echo "[PASS] $test_name (Expected errors caught successfully)"
        else
            echo "[FAIL] $test_name (Expected failure, but compiler exited with 0)"
        fi
    else
        if [ $exit_code -eq 0 ]; then
            echo "[PASS] $test_name (Compiled successfully without errors)"
        else
            echo "[FAIL] $test_name (Compilation failed with exit code $exit_code)"
        fi
    fi
    echo "" >> "$OUTPUT_FILE"
}

echo "[2/3] Running test suite..."
run_test "Test 1: Primitives, Type Inference, Operators & String Concatenation" "tests/test1_primitive_and_inference.swift" 0
run_test "Test 2: Variable Declarations (let immutable vs var mutable)" "tests/test2_immutability_let_var.swift" 0
run_test "Test 3: Control Flow (if, else, switch, case, default)" "tests/test3_control_flow.swift" 0
run_test "Test 4: Loops (while, repeat-while, for-in)" "tests/test4_loops.swift" 0
run_test "Test 5: Functions (Parameters, Return Types, Named Params, Void)" "tests/test5_functions.swift" 0
run_test "Test 6: Arrays (Fixed 1D arrays, Subscript access, Subscript mutation)" "tests/test6_arrays.swift" 0
run_test "Test 7: Structs (Value semantics, Member access with '.', Assignment example)" "tests/test7_structs.swift" 0
run_test "Test 8: Semantic Error Diagnostics" "tests/test8_semantic_errors.swift" 1
run_test "Test 9: Lexical & Syntactic Error Diagnostics" "tests/test9_lexical_syntax_errors.swift" 1

echo "[3/3] Generating submission files and PDF report..."
mkdir -p submission_txt
cp final-compiler/lexer.l submission_txt/lexer.l.txt
cp final-compiler/parser.y submission_txt/parser.y.txt
cp final-compiler/symbol_table.h submission_txt/symbol_table.h.txt
cp final-compiler/symbol_table.cpp submission_txt/symbol_table.cpp.txt
cp final-compiler/tac.h submission_txt/tac.h.txt
cp final-compiler/tac.cpp submission_txt/tac.cpp.txt
cp final-compiler/ast_nodes.h submission_txt/ast_nodes.h.txt
cp final-compiler/compiler_context.h submission_txt/compiler_context.h.txt
cp final-compiler/main.cpp submission_txt/main.cpp.txt
cp final-compiler/Makefile submission_txt/Makefile.txt

python3 generate_pdf_report.py

echo "All tests completed! Full log written to $OUTPUT_FILE"
echo "Submission source files prepared in submission_txt/"
echo "Submission PDF generated: Swift_Subset_Compiler_Report.pdf"
