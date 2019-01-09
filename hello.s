.data
msg:
	.ascii	"Hello, world!\n"
	len = . - msg

.text
	.global _start


_start:
	movl $len,%edx
	movl $msg,%ecx
	movl $1,%ebx
	movl $4,%eax
	int $0x80

	movl $0,%ebx	#param of sys call
	movl $1,%eax	#number of sys call
	int $0x80		#call ISR
