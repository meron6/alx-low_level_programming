Get help from Real Tutors

Copy
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void print_elf_header_info(Elf64_Ehdr *header) {
    printf("Magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class: %d-bit\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);

    printf("Data: %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");

    printf("Version: %d\n", header->e_ident[EI_VERSION]);

    printf("OS/ABI: ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("TRU64 UNIX\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM architecture\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("Standalone (embedded) application\n");
            break;
        default:
            printf("<unknown>\n");
    }

    printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type: ");
    switch (header->e_type) {
        case ET_NONE:
            printf("NONE (No file type)\n");
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
            printf("CORE (Core file)\n");
            break;
        default:
            printf("<unknown>\n");
    }

    printf("Entry point address: 0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error("Usage: elf_header elf_filename");
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        error("Failed to open the file");
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read == -1 || bytes_read != sizeof(header)) {
        error("Failed to read the ELF header");
    }

    if (!(header.e_ident[EI_MAG0] == ELFMAG0 && header.e_ident[EI_MAG1] == ELFMAG1 &&
          header.e_ident[EI_MAG2] == ELFMAG2 && header.e_ident[EI_MAG3] == ELFMAG3)) {
        error("Not an ELF file");
    }

    print_elf_header_info(&header);

    close(fd);

    return 0;
}
