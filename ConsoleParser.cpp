#include <sys/timeb.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#if defined(WIN32)
#define TIMEB _timeb
#define ftime _ftime
#else
#define TIMEB timeb
#endif

int main(int argc, const char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Inadequate parameters");
        return 1;
    }

    if (argc > 2)
    {
        fprintf(stderr, "Too much parameters");
        return 1;
    }

    time_t ltime1, ltime2, tmp_time;
    double t = 0;
    struct TIMEB tstruct1, tstruct2;

    ftime(&tstruct1); // start time ms
    time(&ltime1);    // start time s
    system(argv[1]);
    time(&ltime2);    // end time sec
    ftime(&tstruct2); // end time ms

    tmp_time = (ltime2 * 1000 + tstruct2.millitm) - (ltime1 * 1000 + tstruct1.millitm);
    t = (double) tmp_time;
    t = t / 1000;
    printf("\n----------------------------------------\nProgram exited after %.3f second(s).", t);
    return 0;
}