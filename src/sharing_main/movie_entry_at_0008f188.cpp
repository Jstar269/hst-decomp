/* HSTMATCH module=hstp_trans_main.prx start=0x0008f188 end=0x0008f208 symbol=FUN_0008f188 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Menu.cpp (per its assert `index >= 0 && index < BULK_OF(movie)` at line 1452): refreshes the float of the
   movie table entry `index` from 0x1c0b98 (a member taking the index as its second argument, which is why the
   index lives in a1 from the start) and returns the entry. Names provisional. */
struct Movie {
    int id;
    float t;
};

extern Movie DAT_0037883c[4];       /* movie */
extern char DAT_003eaad8[];
extern const char DAT_0037872c[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_0037885c[];   /* "index >= 0 && index < BULK_OF(movie)" */
extern const char DAT_0037875c[];   /* "Menu.cpp" */

extern "C" {
void FUN_0008d950(...);
float FUN_001c0b98(void *, int);
}

#define BULK_OF(a) (sizeof(a) / sizeof((a)[0]))
#define HST_ASSERT(cond, text, line) do { if (!(cond)) { FUN_0008d950(DAT_0037872c, text, DAT_0037875c, line); for (;;) {} } } while (0)

extern "C" Movie *FUN_0008f188(int index)
{
    HST_ASSERT(index >= 0 && index < BULK_OF(DAT_0037883c), DAT_0037885c, 1452);
    DAT_0037883c[index].t = FUN_001c0b98(DAT_003eaad8, index);
    return &DAT_0037883c[index];
}
