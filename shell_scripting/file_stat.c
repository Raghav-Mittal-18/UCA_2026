#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void print_file_type(mode_t mode)
{
    if (S_ISREG(mode))
        printf("File Type:            Regular File\n");
    else if (S_ISDIR(mode))
        printf("File Type:            Directory\n");
    else if (S_ISLNK(mode))
        printf("File Type:            Symbolic Link\n");
    else if (S_ISCHR(mode))
        printf("File Type:            Character Device\n");
    else if (S_ISBLK(mode))
        printf("File Type:            Block Device\n");
    else if (S_ISFIFO(mode))
        printf("File Type:            FIFO/Named Pipe\n");
    else if (S_ISSOCK(mode))
        printf("File Type:            Socket\n");
    else
        printf("File Type:            Unknown\n");
}

void print_time(time_t t)
{
    char *time_str = ctime(&t);

    if (time_str != NULL)
        printf("%s", time_str);
}

int main(int argc, char *argv[])
{
    struct stat file_stat;

    // Check command-line arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Get file attributes
    if (stat(argv[1], &file_stat) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);

    // File type
    print_file_type(file_stat.st_mode);

    // Permissions
    printf("Permissions:          %04o\n", file_stat.st_mode & 0777);

    // File size
    printf("File Size:            %ld bytes\n", file_stat.st_size);

    // Hard links
    printf("Hard Links Count:     %ld\n", file_stat.st_nlink);

    // Owner and group
    printf("Owner (UID):          %d\n", file_stat.st_uid);
    printf("Group (GID):          %d\n", file_stat.st_gid);

    // Times
    printf("Last Access Time:     ");
    print_time(file_stat.st_atime);

    printf("Last Modification:    ");
    print_time(file_stat.st_mtime);

    printf("Status Change Time:   ");
    print_time(file_stat.st_ctime);

    return 0;
}
