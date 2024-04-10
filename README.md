# CSMC223-Processor-Simulator

# Instruction Set Format:
OPCODES:\
00: mov - Loads data to a data register\
01: store - Stores the data in the accumulator to the indicated memory address\
02: jmp - Unconditional jump\
03: cmp - Compares two data and sets a flag: GREATER THAN, LESS THAN, or EQUAL\
04: jl - Jumps to a code segment if the flag is LESS THAN\
05: jg - Jumps to a code segment if the flag is GREATER THAN\
06: je - Jumps to a code segment if the flag is EQUAL\
07: jne - Jumps to a code segment if the flag is NOT EQUAL\
08: jle - Jumps to a code segment if the flag is LESS THAN OR EQUAL\
09: jge - Jumps to a code segment if the flag is GREATER THAN OR EQUAL\
10: jz - Jumps to a code segment if the flag is ZERO\
11: jnz - Jumps to a code segment if the flag is NOT ZERO\
