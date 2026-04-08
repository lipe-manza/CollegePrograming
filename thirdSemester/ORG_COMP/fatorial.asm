    .data
    .text
    .align 2
    .globl main
main:
    addi a7,zero,5
    ecall
    addi sp,sp,-4
    sw s0,0(sp)
    add s0,a0,zero
    add t0,s0,zero
    addi t1,zero,1
loop:
    beq t0,zero,the_end
    mul t1,t0,t1
    addi t0,t0,-1
    j loop
the_end:
    li a7,1
    add a0,t1,zero
    ecall
    lw s0,0(sp)
    addi sp,sp,4
    li a7,10
    ecall

