
#include <time.h>

extern void __tm_conv();
extern void __asc_conv();

char *
ctime(timep)
time_t * timep;
{
static char cbuf[26];
   struct tm tmb;
   struct timezone tz;
   time_t offt;

   gettimeofday((void*)0, &tz);

   offt = -tz.tz_minuteswest*60L;

   /* tmb.tm_isdst = ? */
   __tm_conv(&tmb, &timep, offt);

   __asc_conv(cbuf, &tmb);

   return cbuf;
}
