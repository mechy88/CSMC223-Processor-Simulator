# CSMC223-Processor-Simulator

**-Instruction Set Format-**

**Opcodes:** (Hexadecimal)

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
0A: jz - Jumps to a code segment if the flag is ZERO\
0B: jnz - Jumps to a code segment if the flag is NOT ZERO\
0C: add - Value of AC + value of memory address; result is stored in the AC\
0D: sub - Value of AC - value of memory address; result is stored in AC

**Registers:**

Size: 32 bits\
PC - Program Counter\
AC - Accumulator\
IR - Instruction Register\
DR - Decoder Register (holder of memory address of the instruction to be executed)

**Control Unit:**
- A class that manipulates PC, AC, IR, & DR
- Contains functions that operate on each opcode\
**NOTE:** Make another class for instruction set that holds ISA; static. 
