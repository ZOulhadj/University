***********************************
*                                 *
*            Building             *
*                                 *
***********************************

Compiler:                   clang (MacOS Compiler)
Build directory:            OUL20475392 folder
Build command:              clang src/main.c src/case_conversion.asm

Build notes:
                            The program should be built outside of the src (source)
                            folder using the build command above. In total there are
                            three source files and one assembly file that need to be
                            compiled.


***********************************
*                                 *
*              Notes              *
*                                 *
***********************************

The purpose of this application is to convert the case of any input data
into upper or lower case. This data can be outputted onto the consolex
or into an output file.

The program makes use of external assembly i.e. the assembly is linked at
compile time with functions declared within the c code.

The main functionality resides within the case_converter.c file and
the case_conversion.asm file. The array.c file contains the code needed
for creating a dynamic array and is used within the case_converter file.


Key Features:
    - Dynamic array
    - External assembly
    - Multiple source files



A few issues that are yet to be fixed:
    - Exception error when reading really large text files
    - Ensuring that user enters arguments in the right order
    - Making sure valid data is set (ie. reading a malformed text file)
