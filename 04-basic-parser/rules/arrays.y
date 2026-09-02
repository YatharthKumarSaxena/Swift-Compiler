array_elements:
      expression
    | array_elements ',' expression
;

array:
      '[' array_elements ']'
;

array_assignment:
      array_access ASSIGN expression
;