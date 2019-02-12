#Nome: João Paulo de Oliveira
#Matrícula: 11611BCC046

	.data
string:	.asciiz ">>>> Hello World, aqui é o João Paulo matricula 11611BCC046"

	.text

li $v0, 4
la $a0, string
syscall

li $v0,10
syscall