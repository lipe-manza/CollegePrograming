    .data
    .align 0

strSrc: .asciz "teste"
strDst: .space 6  # reserve 6 bytes in the static memory

    .text
    .align 2
    .globl
main:
    la t0 , strSrc # put the address of the 1st byte of strSrc into t0(temporary register)
    la t1 , strDst # put the address of the 1st byte of strSrc into t0(temporary register)

loopCopy:
    lb s0, 0(t0) # put the content of what byte t0 is pointing into s0
    sb s0, 0(t1) # put the content of s0 into t1

    addi t0,t0,1
    addi t1,t1,1

    bne s0,zero,loopCopy # branch not equal zero=(\0)

    addi a7,zero , 4    # Print String
    la a0, strDst
    ecall

    addi a7,zero,10     # Finish the program
    ecall
