    .data
    .align 0

strSrc: .asciz "teste" 
strDst: .word # ponteiro
    
    .text
    .align 2
    .globl
main:
    la t0 , strSrc # put the address of the 1st byte of strSrc into t0(temporary register)
    
    addi t3,zero,0 # count

loopCopy:
    lb s0, 0(t0) # put the content of what byte t0 is pointing into s0
    addi t3,t3,1 # incrementa 1 no count

    addi t0,t0,1 # incrementa t0
    

    bne s0,zero,loopCopy # branch not equal zero=(\0)

    addi a7,zero , 9
    add a0,zero,t3
    ecall

    la t1,strDst # save the address of strDst into t1
    sw a0, 0(t1)
    
    addi a7,zero,10
    ecall