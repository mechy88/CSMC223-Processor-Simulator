# CSMC223-Processor-Simulator

Instruction Set Format:\
00: mov - Loads data to a data register\
01: jmp - Unconditional jump\
02: cmp - Compares two data and sets a flag: GREATER THAN, LESS THAN, or EQUAL\
03: jl - Jumps to a code segment if the flag is LESS THAN\
04: jg - Jumps to a code segment if the flag is GREATER THAN\
05: je - Jumps to a code segment if the flag is EQUAL\
06: jne - Jumps to a code segment if the flag is NOT EQUAL\
07: jle - Jumps to a code segment if the flag is LESS THAN OR EQUAL\
08: jge - Jumps to a code segment if the flag is GREATER THAN OR EQUAL\
09: jz - Jumps to a code segment if the flag is ZERO\
10: jnz - Jumps to a code segment if the flag is NOT ZERO\
