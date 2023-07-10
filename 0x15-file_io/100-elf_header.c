#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>

void checkELF(unsigned char *e_ident);
void printOut_magic(unsigned char *e_ident);
void printOut_version(unsigned char *e_ident);
void printOut_entry(unsigned long int e_entry, unsigned char *e_ident);
void closeELF(int elf_FILE);
void printOut_class(unsigned char *e_ident);
void printOut_data(unsigned char *e_ident);
void printOut_abi(unsigned char *e_ident);
void printOut_osabi(unsigned char *e_ident);
void printOut_type(unsigned int e_type, unsigned char *e_ident);

/**
 * checkELF - Checks if a file is an ELF file.
 * @e_ident: pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is NOT an ELF file its exit code is 98.
 */

void checkELF(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printOut_magic - prints the magic numbers of an ELF_header.
 * @e_ident: pointer to an array containing the ELF magic numbers.
 *
 * Description: magic numbers are separated by spaces.
 */

void printOut_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * printOut_class - prints the class of an ELF_header.
 * @e_ident: pointer to an array containing the ELF class.
 */

void printOut_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * printOut_data - Prints the data of an ELF_header.
 * @e_ident: pointer to an array containing the ELF class.
 */

void printOut_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * printOut_version - Prints the version of an ELF_header.
 * @e_ident: pointer to an array containing the ELF version.
 */

void printOut_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * printOut_osabi - prints the OS/ABI of an ELF_header.
 * @e_ident: pointer to an array containing the ELF version.
 */

void printOut_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
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
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * printOut_abi - prints the ABI version of an ELF_header.
 * @e_ident: pointer to an array containing the ELF ABI version.
 */

void printOut_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * printOut_type - prints the type of an ELF_header.
 * @e_type: ELF type.
 * @e_ident: pointer to an array containing the ELF elements.
 */

void printOut_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
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
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * printOut_entry - prints the entry point of an ELF_header.
 * @e_entry: address of the ELF file entry point.
 * @e_ident: pointer to an array containing the ELF class.
 */

void printOut_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * closeELF - Closes an ELF file.
 * @elf_FILE: file descriptor of the ELF file.
 *
 * Description: if the file CANNOT be closed exit is code 98.
 */

void closeELF(int elf_FILE)
{
	if (close(elf_FILE) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf_FILE);
		exit(98);
	}
}

/**
 * main - displays the information contained in the ELF_header at
 * the beginning of an ELF file.
 * @argc: counts of arguments passed to the program at the terminal
 * @argv: array of pointer(s) to the arguments.
 *
 * Return: 0 on success.
 *
 * Description:  NOT an ELF File or the function fails
 * - exit code is 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *ELF_header;
	int open_fd, read_bytes;

	open_fd = open(argv[1], O_RDONLY);
	if (open_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	ELF_header = malloc(sizeof(Elf64_Ehdr));
	if (ELF_header == NULL)
	{
		closeELF(open_fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	read_bytes = read(open_fd, ELF_header, sizeof(Elf64_Ehdr));
	if (read_bytes == -1)
	{
		free(ELF_header);
		closeELF(open_fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	checkELF(ELF_header->e_ident);
	printf("ELF Header:\n");
	printOut_magic(ELF_header->e_ident);
	printOut_class(ELF_header->e_ident);
	printOut_data(ELF_header->e_ident);
	printOut_version(ELF_header->e_ident);
	printOut_osabi(ELF_header->e_ident);
	printOut_abi(ELF_header->e_ident);
	printOut_type(ELF_header->e_type, ELF_header->e_ident);
	printOut_entry(ELF_header->e_entry, ELF_header->e_ident);

	free(ELF_header);
	closeELF(open_fd);
	return (0);
}
