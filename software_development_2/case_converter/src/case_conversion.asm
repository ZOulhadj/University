    // initialise global functions that will be called from within the C code
    .global _char_lower_case
    .global _char_upper_case
    .global _increment_count

_char_lower_case:
    mov %rdi, %rax                // move ascii char code into return register
    add $32, %rax                 // add 32 to ascii code to make it lower case

    ret

_char_upper_case:
    mov %rdi, %rax                // move ascii char code into return register
    sub $32, %rax                 // subtract 32 from ascii code to make it upper case

    ret

_increment_count:
    mov $1, %rax

    ret
