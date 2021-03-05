    // TODO: Checklist
    // align the stack for correct memory access
    // get parameter value (the string to be converted)
    // loop through each character in the string
    // convert the case
    // return converted word back into C

    // rbp is a frame pointer
    // rsp is a stack pointer

    // rdi is the value of the first function parameter
    // rax is used for retuning values.

    // compile command: gcc -masm=intel main.c case_conversion.s

    //    mov al, [rdi]              // dereference char*
    //    sub al, 0x20
    //    mov [rdi], al

    // include function from C
    .extern _putchar
    .extern _toupper

    // initialise global functions that will be called from within the C code
    .global _char_lower_case
    .global _char_upper_case

_char_lower_case:
    mov rax, rdi                // move ascii char code into return register
    add rax, 32                 // add 32 to ascii code to make it lower case

    ret

_char_upper_case:
    mov rax, rdi                // move ascii char code into return register
    sub rax, 32                 // subtract 32 from ascii code to make it upper case

    ret
