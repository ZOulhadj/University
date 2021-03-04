    // TODO: Checklist
    // align the stack for correct memory access
    // get parameter value (the string to be converted)
    // loop through each character in the string
    // convert the case
    // return converted word back into C

    // compile command: gcc -g -masm=intel main.c case_conversion.s


    // include function from C
    .extern _putchar
    .extern _toupper

    // initialise global functions that will be called from within the C code
    .global _char_lower_case
    .global _char_upper_case

    // %rbp is a frame pointer
    // %rsp is a stack pointer
    //    mov al, [rdi]              // dereference char*
    //    sub al, 0x20
    //    mov [rdi], al
_char_lower_case:
    mov rdi, [rdi]              // dereference char*
    push rdi                    // add character onto the stack
    call _putchar
    pop rdi                     // remove character from stack

    ret

_char_upper_case:
    ret
