	.data

	.align 0 # Alinha para 1 byte
str1:   .asciz "Hello World++!"  # String para numeros >= 0
str2:   .asciz "Hello World--!"  # String para numeros negativos

	.text
	.align 2 # Alinhar para 32bits (4 bytes)
	.globl main
main: 	addi a7,zero,5 # Salva o codigo da syscall 5 (readInt) no a7
		ecall	       # Carrega a syscall do a7 , le o input e salva no a0

		add s0,a0,zero # Salva a0 em s0

	    blt s0,zero,print_neg # Branch less than (if(s0<zero)) pula para print_neg se for negativo
		addi a7,zero,4        # Salva o codigo da syscall 4 (printString) no a7 
		la a0,str1            # Salva str1 no registrador a0 (endereco da string)
		ecall                 # Carrega a syscall do a7 , e printa o conteudo do a0
		j the_end             # Pula para o final do programa

print_neg: addi a7,zero,4 # Salva o codigo da syscall 4 (printString) no a7
		la a0,str2             # Salva str2 no registrador a0 (endereco da string)
		ecall                  # Carrega a syscall do a7 , e printa o conteudo do a0

the_end: addi a7,zero,1   # Salva o codigo da syscall 1 (printInt) no a7
		add a0,zero,s0         # Salva o valor de s0 em a0 para ser impresso
		ecall                  # Carrega a syscall do a7 , e printa o inteiro

		li a7,10               # Salva o codigo da syscall 10 (exit) no a7
		ecall                  # Finaliza o programa