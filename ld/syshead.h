
#ifndef STDC_HEADERS_MISSING
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#endif

#ifndef POSIX_HEADERS_MISSING
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif

#ifdef MSDOS
#undef POSIX_HEADERS_MISSING

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define A_OUT_INCL	"a_out.h"
#undef min
#define R_OK	0
#define mode_t		unsigned short
#define SEEK_SET	0
#define STDOUT_FILENO	0
#endif

#ifndef A_OUT_INCL
#define A_OUT_INCL	"a.out.h"
#endif

#ifndef O_BINARY
#define O_BINARY	0
#endif

/******************************************************************************/

/* EEEEyuk!! */

#ifdef __STDC__
#define P(x)	x
#else
#define P(x)	()
#endif

#ifdef STDC_HEADERS_MISSING
extern int errno;
char *strcat P((char *dest, const char *src));
unsigned long strtoul P((const char *s, char **endptr, int base));
void exit P((int status));
void *malloc P((unsigned size));
int strncmp P((const char *s1, const char *s2, unsigned n));
char *strncpy P((char *dest, const char *src, unsigned n));
char * strcpy P((char* dest, char* src));
void *memset P((void *s, int c, unsigned n));
#endif

#ifdef POSIX_HEADERS_MISSING
#include <sys/types.h>
#include <sys/stat.h>

#define R_OK	0
int access P((const char *path, int amode));
#define SEEK_SET	0
#define STDOUT_FILENO	0

#define mode_t		unsigned short
#define off_t		long

int chmod P((const char *path, int mode));
int close P((int fd));
int creat P((const char *path, int mode));
int fstat P((int fd, struct stat *statbuf));
off_t lseek P((int fd, off_t offset, int whence));
int open P((const char *path, int oflag, ...));
int read P((int fd, void *buf, unsigned nbytes));
mode_t umask P((int oldmask));
int write P((int fd, const void *buf, unsigned nbytes));
#endif

#ifndef A_OUT_INCL
# ifdef BSD_A_OUT
#  ifdef STANDARD_GNU_A_OUT
#   define A_OUT_INCL <a.out.h>
#  else
#   define A_OUT_INCL "bsd-a.out.h"
#  endif

#  ifdef MSDOS
#   define A_OUT_INCL "a_out.h"
#  else
#   define A_OUT_INCL "a.out.h"	/* maybe local copy of <a.out.h> for X-link */
#  endif
# endif /* BSD_A_OUT */
#endif

# ifdef BSD_A_OUT
#  ifdef STANDARD_GNU_A_OUT
#   define RELOC_INFO_SIZE 8	/* unportable bitfields - bcc doesn't pack */
#  else
#   define RELOC_INFO_SIZE (sizeof (struct relocation_info))
#  endif
#  define C_EXT N_EXT
#  define C_STAT 0
#  define n_was_name n_un.n_name
#  define n_was_numaux n_other
#  define n_was_other n_numaux
#  define n_was_sclass n_type
#  define n_was_strx n_un.n_strx
#  define n_was_type n_desc
# else /* not BSD_A_OUT */
#  define n_was_name n_name
#  define n_was_numaux n_numaux
#  define n_was_other n_other
#  define n_was_sclass n_sclass
#  define n_was_strx n_value
#  define n_was_type n_type
# endif /* BSD_A_OUT */

