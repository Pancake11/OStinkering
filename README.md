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

makefile has been added and i have moved to VM  to dev this so it will prob not work with the WSL.
furthermore i have cross compiled gcc to compile in ix86 (i386 or i686) in a special file so you should integrate the right path to compile in the makefile.
this is now going a bit bigger will have soon to move on from bootsector to proper bootsuit for the projet.
Will probably use the meaty skeleton from os dev wiki and will probably use the proposed implementation to multiboot the os.


