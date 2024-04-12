# CSMC223-Processor-Simulator


## To Run
    g++ main.cpp

## Instruction Set Format

**Opcodes:** (Hexadecimal)

00: mov - Loads data to a data register\
01: store - Stores the data in the accumulator to the indicated memory address\
02: jmp - Unconditional jump\
03: add - Value of AC + value of memory address; result is stored in the AC\
04: sub - Value of AC - value of memory address; result is stored in AC\
05: mul - Value of AC * value of memory address; result is stored in AC\
06: div - Value of AC / value of memory address; result is stored in AC\
07: load - Value in indicated memory loaded to desired register

**Registers:**

Size: 32 bits
00 - General Purpose Register\
01 - General Purpose Register\
02 - General Purpose Register\
03 - General Purpose Register\
AC - Accumulator\
MDR - Memory Data Register\
MAR - Memory Address Register