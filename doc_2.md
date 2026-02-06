# Problem:
Write a program to convert an infix mathematical expression to postfix and evaluate it.
# My Solution

## Files

- prog_2.c
- stack.h
- stack.c

## Compile and Run

```bash
g++ prog_2.c stack.c -o prog_2
./prog_2
```

## Supported Operators

- +, -, *, /, %, ^
- Brackets: ( ), { }, [ ]

## Operator Priority

1. ^ (highest)
2. *, /, %
3. +, - (lowest)

## Examples

```
a+b*c-d → abc*+d-
a^b+b*c-d → ab^bc*+d-
a+(b*c)-d → abc*+d-
```

## How It Works

1. Scan expression left to right
2. Add operands directly to output
3. For operators, compare with stack top
4. Push if higher priority, pop if lower
5. Handle brackets separately
6. Pop remaining operators at end

## Functions

- get_priority() - returns priority number for operators
- get_associativity() - checks operator associativity
- check_priority() - compares priorities and decides push/pop
- convert_to_postfix() - main conversion function

## Notes

- Works with single character operands only
- Uses numbers 1-3 for operator priority
- Brackets use 4-6 and their squares for matching