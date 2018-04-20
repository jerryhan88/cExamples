#define NAME_MAX 14

typedef struct {
	long ino;
	char name[NAME_MAX + 1];
} Dirent;

typedef struct {
	int fd;
	Dirent d;
} DIR;

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);


struct stat
{
	dev_t 
};


char *name;
struct stat stbuf;
int stat(char *, struct stat *);
stat(name, &stbuf);