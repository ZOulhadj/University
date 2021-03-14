***********************************
*                                 *
*            Building             *
*                                 *
***********************************

Compiler:                   clang (LLVM)
Build directory:            Build/
Build command:              clang ../src/main.c ../src/case_conversion.asm

Build notes:
                            This program was build on macOS using LLVM's compiler
                            called clang. A pre-built program has been provided
                            within the build folder.

                            You can build the project from within the `Build`
                            directory using the following command (Build command):

                            clang ../src/main.c ../src/case_conversion.asm

                            This will create the executable which you can
                            then run.


***********************************
*                                 *
*              Notes              *
*                                 *
***********************************

The purpose of this application is to convert the case of any input data
into upper or lower case. This data can be outputted onto the console
or into an output file.

The program makes use of external assembly i.e. the assembly is linked at
compile time with functions declared within the c code.


Key Features:
    - Dynamic array
    - External assembly


A few issues that are yet to be fixed:
    - Exception error when reading really large text files
    - Ensuring that user enters arguments in the right order
    - Making sure valid data is set (ie. reading a malformed text file)
