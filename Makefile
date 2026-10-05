all:
	$(MAKE) -C final-compiler

test:
	./run_all_tests.sh

pdf:
	python3 generate_pdf_report.py

clean:
	$(MAKE) -C final-compiler clean
	rm -f COMPILER_EXECUTION_RESULTS.txt Swift_Subset_Compiler_Report.pdf
	rm -rf submission_txt

.PHONY: all test pdf clean
