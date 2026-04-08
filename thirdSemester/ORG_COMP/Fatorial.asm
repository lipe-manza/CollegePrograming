    .data
    .align 2

strInput: .asciz "Digite um numero >=0: "
strResp1: .asciz "O fatorial de "
strResp2: .asciz " eh "
strErro:  .asciz "Entrada invalida\n"

    .text
    .align 2
    .globl main
main:
    addi sp,sp,-4
    sw s0,0(sp)

loopReadInput:
    addi a7,zero,4
    la a0,strInput
    ecall
    addi a7,zero,5
    ecall
    bge a0,zero,continue

    addi a7,zero,4
    la a0,strErro
    ecall
    j loopReadInput

continue:
    add s0,zero,a0
    jal fatorial

    addi a7,zero,4
    la a0,strResp1
    ecall

    addi a7,zero,1
    add a0,zero,s0
    ecall

    addi a7,zero,4
    la a0,strResp2
    ecall

    addi a7,zero,1
    add a0,zero,a1
    ecall

    lw s0,0(sp)
    addi sp,sp,4
    addi a7,zero,10
    ecall

fatorial:
    addi sp,sp,-8
    sw ra,0(sp)
    sw a0,4(sp)

    beq a0,zero,return1

    addi a0,a0,-1
    jal fatorial

    lw a0,4(sp)
    mul a1,a1,a0

    j retornaFat

return1:
    addi a1,zero,1

retornaFat:
    lw ra,0(sp)
    lw a0,4(sp)
    addi sp,sp,8
    jr ra



