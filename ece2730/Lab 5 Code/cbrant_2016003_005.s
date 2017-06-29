# Christopher Brant
# Lab 5
# Sec 003

# Begin assembly stub

.globl Fib
.type Fib, @function
Fib:
     # Prolog
     pushl %ebp
     pushl %ebx
     movl %esp, %ebp
     subl $8, %esp

     # My Code
     movl global_var, %eax   # Because global_var is set to be local_var
     movl $0, %ebx
     movl %eax, -4(%ebp)
     cmp $0, -4(%ebp)        # Compare and return if necessary
     je return
     cmp $1, -4(%ebp)        # Compare and return if necessary
     je return

     movl -4(%ebp, %eax)     # Move from the stack into A register
     subl $1, %eax
     movl %eax, global_var
     call Fib                # Recall beginning of the function for recursion

     movl global_var, %eax
     movl %eax, -8(%ebp)
     movl -4(%ebp), %eax
     subl $2, %eax
     movl %eax, global_var
     call Fib                # Recall beginning of the function for recursion

     movl global_var, %eax
     movl -8(%ebp), %ebx
     addl %ebx, %eax         # Add vars together for Fib sequence
     incl %ebx
     movl %eax, global_var   # Move number back to global_var

return:
     # Epilog
     movl %ebp, %esp
     popl %ebx
     popl %ebp
     ret

.comm global_var, 4

# End Assembly Stub

