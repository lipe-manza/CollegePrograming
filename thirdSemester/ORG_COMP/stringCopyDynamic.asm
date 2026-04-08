    .data
    .align 0

strSrc: .asciz "teste"
    .align 2
strDst: .word 0

    .text
    .globl main
main:
    addi sp,sp,-4
    sw s0,0(sp)

    la t0,strSrc
    addi t3,zero,0

loopTam:
    lb t2,0(t0)
    addi t3,t3,1
    addi t0,t0,1
    bne t2,zero,loopTam

    addi a7,zero,9
    add a0,zero,t3
    ecall

    la t1,strDst
    sw a0,0(t1)

    la t0,strSrc
    lw t2,0(t1)

loopCopy:
    lb s0,0(t0)
    sb s0,0(t2)
    addi t0,t0,1
    addi t2,t2,1
    bne s0,zero,loopCopy


    addi a7,zero , 4    # Print String
    la a0, strDst
    ecall

    addi a7,zero,10     # Finish the program
    ecall
