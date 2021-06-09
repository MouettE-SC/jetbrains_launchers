#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#if defined(INTELLIJ)
#define DIRECTORY "IDEA-U"
#define BINARY "idea64.exe"
#elif defined(DATAGRIP)
#define DIRECTORY "datagrip"
#define BINARY "datagrip64.exe"
#elif defined(PYCHARM)
#define DIRECTORY "PyCharm-P"
#define BINARY "pycharm64.exe"
#endif

int  WinMain() {
    DIR *d;
    struct dirent *dir;
    char best[56], current[56], *pos, path[256];
    int err;

    d = opendir("C:\\tools\\Jetbrains\\apps\\" DIRECTORY "\\ch-0");
    memset(best, '\0', 56);
    best[0] = '0';
    memset(current, '\0', 56);
    while ((dir = readdir(d)) != NULL) {
        strcpy(current, dir->d_name);
        pos = strrchr(current, '.');
        if ( strcmp(pos, ".vmoptions") == 0 ) {
            current[pos - current] = '\0';
            if (strcmp(current, best) > 0)
                strcpy(best, current);
        }
    }
    closedir(d);
    strcpy(path, "C:\\tools\\Jetbrains\\apps\\" DIRECTORY "\\ch-0\\");
    strcat(path, best);
    strcat(path, "\\bin\\" BINARY);
    execl(path, path, NULL);
    return errno;
}
