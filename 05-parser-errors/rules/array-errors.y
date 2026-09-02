array_error:
      '[' ']'
      {
          printf("Parser Error: Empty array is not allowed.\n");
      }
    | '[' array_elements
      {
          printf("Parser Error: Missing closing ']' in array.\n");
      }
    | '[' expression expression ']'
      {
          printf("Parser Error: Missing ',' between array elements.\n");
      }
    | '[' array_elements ','
      {
          printf("Parser Error: Trailing ',' in array.\n");
      }
;

array_access_error:
      IDENTIFIER '[' ']'
      {
          printf("Parser Error: Array index is missing.\n");
      }
    | IDENTIFIER '[' expression
      {
          printf("Parser Error: Missing closing ']' in array access.\n");
      }
;