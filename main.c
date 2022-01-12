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
#elif defined(CLION)
#define DIRECTORY "CLion"
#define BINARY "clion64.exe"
#elif defined(PHPSTORM)
#define DIRECTORY "PhpStorm"
#define BINARY "phpstorm64.exe"
#elif defined(GOLAND)
#define DIRECTORY "Goland"
#define BINARY "goland64.exe"
#elif defined(WEBSTORM)
#define DIRECTORY "WebStorm"
#define BINARY "webstorm64.exe"
#endif

int  WinMain() {
    DIR *p,*d;
    struct dirent *channel_dir,*dir;
    char best[56], current[56], *pos, channel[56], ppath[256], path[256];

    p = opendir("C:\\tools\\Jetbrains\\apps\\" DIRECTORY);
    memset(ppath, '\0', 256);
    memset(channel, '\0', 56);
    memset(best, '\0', 56);
    best[0] = '0';
    memset(current, '\0', 56);
    while ((channel_dir = readdir(p)) != NULL ) {
        if (strncmp(channel_dir->d_name, "ch-", 3) != 0)
            continue;
        strcpy(ppath, "C:\\tools\\Jetbrains\\apps\\" DIRECTORY "\\");
        strcat(ppath, channel_dir->d_name);
        d = opendir(ppath);
        while ((dir = readdir(d)) != NULL) {
            strcpy(current, dir->d_name);
            pos = strrchr(current, '.');
            if (pos != NULL && strcmp(pos, ".vmoptions") == 0) {
                current[pos - current] = '\0';
                if (strcmp(current, best) > 0) {
                    strcpy(best, current);
                    strcpy(channel, channel_dir->d_name);
                }
            }
        }
        closedir(d);
    }
    closedir(p);
    strcpy(path, "C:\\tools\\Jetbrains\\apps\\" DIRECTORY "\\");
    strcat(path, channel);
    strcat(path, "\\");
    strcat(path, best);
    strcat(path, "\\bin\\" BINARY);
    execl(path, path, NULL);
    return errno;
}
