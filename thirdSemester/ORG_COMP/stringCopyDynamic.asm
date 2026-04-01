    .data
    .align 0

strSrc: .asciz "teste"
    .align 2
strDst: .word # ponteiro

    .text
    .globl
main:
    la t0 , strSrc # put the address of the 1st byte of strSrc into t0(temporary register)

    addi t3,zero,0 # count

loopTam:
    lb s0, 0(t0) # put the content of what byte t0 is pointing into s0
    addi t3,t3,1 # incrementa 1 no count

    addi t0,t0,1 # incrementa t0

    bne s0,zero,loopCopy # branch not equal zero=(\0)

    addi a7,zero , 9 # Aloca na heap
    add a0,zero,t3   # adiciona o tamanho a ser alocado a0=t3(bytes)
    ecall            # aloca na heap e retorna para a0 = endereco do primeiro byte alocado

    la t1,strDst # save the address of strDst into t1
    sw a0, 0(t1) # Store World em t1(strDst)

    la t0 , strSrc  # t0 = endereco string origem
    la t1 , strDst  # t1 = endereco string destino
    lw t2 , 0(t1)   # t2 = endereco do qual t1 armazena(endereco na heap)

loopCopy:           # loop for copy the string into the heap
    lb s0 , 0(t0)
    sb s0 , 0(t2)
    addi t0,t0,1
    addi t2,t2,1
    bne s0,zero,loopCopy


    addi a7,zero , 4    # Print String
    la a0, strDst
    ecall

    addi a7,zero,10     # Finish the program
    ecall
