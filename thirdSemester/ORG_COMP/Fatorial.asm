    .data
    .align

strInput: .asciz "Digite um numero >=0: "
strResp1: .asciz "O fatorial de  "
strResp2: .asciz " eh "
strErro:  .asciz "Entrada invalida\n"

    .text
    .align 2
    .globl main
main:
loopReadInput: # Print strInput and read the IO
    # Print strInput
    addi a7,zero,4
    la a0,strInput
    ecall
    # Read the input
    addi a7,zero,5
    ecall
    bge,zero,continue # Branch greater or equal then zero

    # else print ERRO
    addi a7 ,zero , 4
    la a0 , strErro
    ecall
    j loopReadInput  # jump to loop

continue:
    # call fatorial function
    # Parameter a0 = n
    # return a1 = fatorial
    add S0 , zero , a0 # Save the read value into s0
    jal fatorial
    # Print strResp1
    addi a7 ,zero , 4
    la a0 , strResp1
    ecall
    # Print n
    addi a7 ,zero , 4
    add a0 ,zero, S0
    ecall

    # Print strResp2
    addi a7 ,zero , 4
    la a0 , strResp2
    ecall

    # Print fatorial
    addi a7 ,zero , 4
    add a0 ,zero , a1
    ecall

    addi a7 , zero , 10
    ecall

fatorial:
    add t0 ,zero ,a0
    addi a1 , zero , 1

loopFat:
    bne t0 , zero , exit
    mul a1 ,a1 , t0
    addi a1 , zero , 1
    j loopFat

exit: jr ra



