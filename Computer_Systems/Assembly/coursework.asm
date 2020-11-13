; set 'main' to be visible outside of this file and for the linker
global main

; macros for system calls
SYS_WRITE equ 4
SYS_READ  equ 3
STDOUT    equ 1
STDIN     equ 0

; declare initialised variables
SECTION .data
    string db "Enter a command (1, 2, 3, q): "

    ; string messages and string lengths for choices
    choice1_string db "Welcome to my assembly program.", 0xa
    choice1_string_len equ $ - choice1_string

    choice2_string db "The second choice.", 0xa
    choice2_string_len equ $ - choice2_string

    choice3_string db "The last choice.", 0xa
    choice3_string_len equ $ - choice3_string

    choiceq_string db "Goodbye.", 0xa
    choiceq_string_len equ $ - choiceq_string

    error_string db "Error, please try again", 0xa
    error_string_len equ $ - error_string

; declare uninitialised variables
SECTION .bss
    input: resb 2 ; reserve 2 bytes of memory for user input

SECTION .text

; entry point
main:

; input loop
loop:
    ; print input command string
    mov edx, 30           ; set string length since it wont change
    mov ecx, string       ; move print to be printed into the ecx register
    mov ebx, STDOUT       ; set file descriptor (stdout)
    mov eax, SYS_WRITE    ; ask kernel to write buffer
    int 0x80              ; call kernel to perform previously set operations (interrupt)

    ; read user input
    mov edx, 2            ; set input buffer length
    mov ecx, input        ; move input buffer memory address into the ecx register
    mov ebx, STDIN        ; set the file descriptor (stdin)
    mov eax, SYS_READ     ; ask kernel to read the user input
    int 0x80              ; call kernel to perform previously set operations (interrupt)

    mov al, [input]       ; move the contents of the input buffer into the al register

    ; compare the given input with different values (1, 2, 3, q)
    ; if the input is equal to a certain value then jump to a specific code block
    cmp al, '1'
    je choice_1

    cmp al, '2'
    je choice_2 

    cmp al, '3'
    je choice_3
    
    cmp al, 'q'
    je choice_q

    ; if the contents of input does not equal any of the above options
    ; jump to the error code block
    jne error

    ; exit the program
    jmp exit

; print the string and jump to the start of the program
choice_1:
    mov edx, choice1_string_len
    mov ecx, choice1_string
    mov ebx, STDOUT
    mov eax, SYS_WRITE
    int 0x80
    jmp loop

; print the string and jump to the start of the program
choice_2:
    mov edx, choice2_string_len
    mov ecx, choice2_string
    mov ebx, STDOUT
    mov eax, SYS_WRITE
    int 0x80
    jmp loop

; print the string and jump back to the start of the program
choice_3:
    mov edx, choice3_string_len
    mov ecx, choice3_string
    mov ebx, STDOUT
    mov eax, SYS_WRITE
    int 0x80
    jmp loop

; print the quit message and jump to the exit code block
choice_q:
    mov edx, choiceq_string_len
    mov ecx, choiceq_string
    mov ebx, STDOUT
    mov eax, SYS_WRITE
    int 0x80
    jmp exit

; print the error string if an incorrect value is given by the user
; then jump to the start of the program
error:
    mov edx, error_string_len
    mov ecx, error_string
    mov ebx, STDOUT
    mov eax, SYS_WRITE
    int 0x80
    jmp loop

; instructions to exit the program
exit:
    mov ebx, 0
    mov eax, 1
    int 0x80
