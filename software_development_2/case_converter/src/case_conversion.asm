    // initialise global functions that will be called from within the C code
    .global _char_lower_case
    .global _char_upper_case
    .global _increment_count
    .extern _printf

_char_lower_case:
    mov rax, rdi                // move ascii char code into return register
    add rax, 32                 // add 32 to ascii code to make it lower case

    ret

_char_upper_case:
    mov rax, rdi                // move ascii char code into return register
    sub rax, 32                 // subtract 32 from ascii code to make it upper case

    ret

    // todo: continue working on this
_increment_count:
    mov rax, 1

    ret
