    .data
    .align 0

strSrc: .asciz "teste"
strDst: .space 6

    .text
    .align 2
    .globl main
main:
    addi sp,sp,-4
    sw s0,0(sp)

    la t0,strSrc
    la t1,strDst

loopCopy:
    lb s0,0(t0)
    sb s0,0(t1)
    addi t0,t0,1
    addi t1,t1,1
    bne s0,zero,loopCopy

    addi a7,zero , 4    # Print String
    la a0, strDst
    ecall

    addi a7,zero,10     # Finish the program
    ecall
