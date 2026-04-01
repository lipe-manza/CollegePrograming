    .data
    .text
    .align 2
    .globl main

main:
    addi a7,zero,5      # ler o n
    ecall

    # salva em s0
    add s0,zero,a0

    # chama a funcao, resultado em a1
    jal fatorial

    # imprimir resultado
    addi a7,zero,1
    add a0,zero,a1
    ecall

    # finalizar programa
    addi a7,zero,10
    ecall

#-------------------------------2
fatorial:
    # empilhar ra e a0
    addi sp,sp,-8
    sw ra,0(sp)
    sw a0,4(sp)

    # if (n == 0)
    beq a0,zero,return1

    # diminui 1 em a0 e chama a funcao recursiva
    addi a0,a0,-1
    jal fatorial

    # incrementa de volta o a0
    addi a0,a0,1

    # multiplica a1 por a0 (n*(n-1))
    mul a1,a1,a0

    j retornaFat

# caso base
return1:
    addi a1,zero,1

retornaFat:
    # desempilhar e restaurar ra e a0
    lw ra,0(sp)
    lw a0,4(sp)
    addi sp,sp,8
    jr ra
