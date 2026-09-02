while_statement:
      WHILE expression '{' statements '}'
;

repeat_while_statement:
      REPEAT '{' statements '}' WHILE expression
;

for_in_statement:
      FOR IDENTIFIER IN expression '{' statements '}'
;