#!/usr/bin/env python3
"""
Generates a PDF report containing sample Swift programs with corresponding
compiler outputs (tokens, parsing messages, symbol tables, TAC, and errors).
Uses PostScript generation piped to ps2pdf.
"""

import os
import subprocess

def escape_ps(text):
    text = text.replace('\\', '\\\\')
    text = text.replace('(', '\\(')
    text = text.replace(')', '\\)')
    # replace unprintable / high ascii characters
    clean = []
    for ch in text:
        if 32 <= ord(ch) <= 126:
            clean.append(ch)
        elif ch == '\t':
            clean.append('    ')
        else:
            clean.append(' ')
    return "".join(clean)

def build_pdf():
    input_file = "COMPILER_EXECUTION_RESULTS.txt"
    if not os.path.exists(input_file):
        print(f"Error: {input_file} not found.")
        return

    with open(input_file, 'r', encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()

    ps_lines = []
    ps_lines.append("%!PS-Adobe-3.0")
    ps_lines.append("%%BoundingBox: 0 0 595 842")  # A4 size
    ps_lines.append("%%Pages: (atend)")
    ps_lines.append("%%EndComments")

    lines_per_page = 64
    margin_left = 36
    start_y = 806
    line_height = 11.5

    current_line_in_page = 0
    page_num = 1

    ps_lines.append(f"%%Page: {page_num} {page_num}")
    ps_lines.append("/Courier findfont 8.5 scalefont setfont")
    ps_lines.append(f"{margin_left} {start_y} moveto")

    for raw_line in lines:
        line = raw_line.rstrip('\r\n')
        # Wrap long lines (> 90 chars)
        chunks = []
        if len(line) <= 90:
            chunks.append(line)
        else:
            while len(line) > 90:
                chunks.append(line[:90])
                line = "    " + line[90:]
            chunks.append(line)

        for chunk in chunks:
            if current_line_in_page >= lines_per_page:
                # End current page
                ps_lines.append(f"/Helvetica findfont 8 scalefont setfont")
                ps_lines.append(f"540 25 moveto ({page_num}) show")
                ps_lines.append("showpage")
                page_num += 1
                ps_lines.append(f"%%Page: {page_num} {page_num}")
                ps_lines.append("/Courier findfont 8.5 scalefont setfont")
                current_line_in_page = 0

            y = start_y - (current_line_in_page * line_height)
            # Styling titles or headers
            if chunk.startswith("TEST:") or chunk.startswith("==="):
                ps_lines.append("/Courier-Bold findfont 9 scalefont setfont")
                ps_lines.append(f"{margin_left} {y} moveto ({escape_ps(chunk)}) show")
                ps_lines.append("/Courier findfont 8.5 scalefont setfont")
            else:
                ps_lines.append(f"{margin_left} {y} moveto ({escape_ps(chunk)}) show")

            current_line_in_page += 1

    # End final page
    ps_lines.append(f"/Helvetica findfont 8 scalefont setfont")
    ps_lines.append(f"540 25 moveto ({page_num}) show")
    ps_lines.append("showpage")
    ps_lines.append("%%Trailer")
    ps_lines.append(f"%%Pages: {page_num}")
    ps_lines.append("%%EOF")

    ps_filename = "report_temp.ps"
    pdf_filename = "Swift_Subset_Compiler_Report.pdf"

    with open(ps_filename, 'w', encoding='utf-8') as f:
        f.write("\n".join(ps_lines))

    # Convert to PDF using ps2pdf
    cmd = ["ps2pdf", ps_filename, pdf_filename]
    subprocess.run(cmd, check=True)
    if os.path.exists(ps_filename):
        os.remove(ps_filename)

    print(f"Generated {pdf_filename} successfully ({page_num} pages)!")

if __name__ == "__main__":
    build_pdf()
