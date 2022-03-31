# OStinkering
Just messing with an simple Os developpement
based on the univ course https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf
and also on the tutorial following above course on git https://github.com/cfenollosa/os-tutorial

Since i'm working on WSL some problem will appear for everyone in the same configuration, 
in the 16 bits mode you should be able to compile with qemu-system-x86_64 --nographic main.bin
the vga output that you will have when starting to use 32 bit protected mode will not appear if using the above mentionned command
you should use qemu-system-x86_64 --nographic --curses main.bin to see if everything works even tho the
displaying will be akward
everything is described in this issue on git : https://github.com/cfenollosa/os-tutorial/issues/195
using a normal linux vm/machine should work good too 
