***********************************
*                                 *
*            Building             *
*                                 *
***********************************

Compiler:                   GCC (GNU Compiler)
Build directory:            OUL20475392 folder
Build command:              gcc -masm=intel src/main.c src/case_converter.c src/array.c src/case_conversion.asm

Notes:                      This program used external assembly using the intel syntax
                            and therefore, this must be indicated to the GCC compiler.
                            This is done using the following argument -masm=intel

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
into upper or lower case. This data can be outputted onto the console
or into an output file.






Key Features:

    - Dynamic array
    - External assembly
    - Multiple source files
