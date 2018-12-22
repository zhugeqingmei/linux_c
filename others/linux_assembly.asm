#PURPOSE: Simple program that exits and returns a
# status code back to the Linux kernel
#
#INPUT: none
#
#OUTPUT: returns a status code. This can be viewed
# by typing
#
# echo $?
#
# after running the program
#
#VARIABLES:
# %eax holds the system call number
# %ebx holds the return status
#
#.section .data
#.section .text
#.globl _start
#_start:
#movl $1, %eax   # this is the linux kernel command
#                # number (system call) for exiting
#                # a program
#movl $4, %ebx   # this is the status number we will
#                # return to the operating system.
#                # Change this around and it will
#                # return different things to
#                # echo $?
#int $0x80       # this wakes up the kernel to run
                # the exit command


.section .data
data_items: #These are the data items
    .long 3,67,34,222,45,75,54,34,44,33,22,11,66,0

.section .text
.globl _start
_start:
    movl $0, %edi                   # move 0 into the index register
    movl data_items(,%edi,4), %eax  # load the first byte of data
    movl %eax, %ebx                 # since this is the first item, %eax is 
                                    # the biggest
start_loop:                         # start loop   
    cmpl $0, %eax                   # check to see if we've hit the end
    je loop_exit
    
    incl %edi                       # load next value
    movl data_items(,%edi,4), %eax
    cmpl %ebx, %eax                 # compare values
    jle start_loop                  # jump to loop beginning if the new
                                    # one isn't bigger
    movl %eax, %ebx                 # move the value as the largest
    jmp start_loop                  # jump to loop beginning
loop_exit:
                                    # %ebx is the status code for the _exit system call
                                    # and it already has the maximum number
    movl $1, %eax                   # 1 is the _exit() syscall
    int $0x80
