#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * error_exit - Prints an error message and exits with status code 98.
 * @msg: The error message to print.
 */
void error_exit(char *msg)
{
fprintf(stderr, "%s", msg);
exit(98);
}

/**
 * main - Displays the information contained in the ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
int fd, i;
Elf64_Ehdr header;

if (argc != 2)
error_exit("Usage: elf_header elf_filename\n");

fd = open(argv[1], O_RDONLY);
if (fd == -1)
error_exit("Error: Cannot open file\n");

if (read(fd, &header, sizeof(header)) != sizeof(header))
error_exit("Error: Cannot read file\n");

if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3)
error_exit("Error: Not an ELF file\n");

printf("Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x ", header.e_ident[i]);
printf("\n");

printf("Class:                             ");
switch (header.e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
}

printf("Data:                              ");
switch (header.e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", header.e_ident[EI_DATA]);
}

printf("Version:                           %d\n", header.e_ident[EI_VERSION]);

printf("OS/ABI:                            ");
switch (header.e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_AIX:
printf("UNIX - AIX\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_MODESTO:
printf("Novell - Modesto\n");
break;
case ELFOSABI_OPENBSD:
printf("UNIX - OpenBSD\n");
break;
default:
printf("<unknown: %x>\n", header.e_ident[EI_OSABI]);
}

printf("ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

printf("Type:                              ");
switch (header.e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n")
break;
default:
printf("<unknown: %x>\n", header.e_type);
}

printf("Entry point address:               %#lx\n", header.e_entry);

printf("Format
