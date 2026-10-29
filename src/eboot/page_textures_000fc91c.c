/* HSTMATCH module=EBOOT.BIN start=0x000fc91c end=0x000fcb7c symbol=FUN_000fc91c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen-side ram dump) corrected by hand: the four texture selections are written out once per slot (a loop is not unrolled by MWCC here because each block calls out), the shared flag is a plain `char` (lb), the registered callback is FUN_000fcb7c (0x10 << 16 with the sign-extended -13444), and the fallback strings are the empty names at 0x2c0e18/1c/20; readability pass; exact match verified; names and types await human review. */
#include "hst/text_bank_lookup.h"

extern char DAT_0033a040;
extern unsigned char DAT_0033a050;
extern int DAT_0033a054;
extern TextHeader *DAT_0033a058;
extern TextGroup *DAT_0033a05c;
extern char DAT_0033a044[];
extern char DAT_0033a060[];
extern char DAT_0033a1e0[];
extern char DAT_0033a360[];
extern char DAT_0033a4e0[];
extern void *DAT_002d836c;
extern void *DAT_002d8370;
extern void *DAT_002d8374;
extern void *DAT_002d8378;
extern int DAT_0034176c;
extern void FUN_00000f74(void *, void (*)(void), void *);
extern void FUN_0010ad1c(void *, int);
extern void *FUN_00198278(int, const char *, int, void *);
extern void FUN_000fcb7c(void);

/* Builds the four page textures, each from the first four names of text group 0. */
void FUN_000fc91c(int owner)
{
    TextGroup *group;
    const char *name;

    if (DAT_0033a040 == 0) {
        DAT_0033a050 = 0;
        DAT_0033a054 = 0;
        FUN_00000f74(&DAT_0033a050, FUN_000fcb7c, DAT_0033a044);
        DAT_0033a040 = 1;
    }
    FUN_0010ad1c(&DAT_0033a050, owner);

    if (DAT_0033a054 == 0) {
        name = DAT_002c0e20;
    } else if (DAT_0033a058->groupCount < 1) {
        name = DAT_002c0e1c;
    } else if ((group = DAT_0033a05c)->count < 1) {
        name = DAT_002c0e18;
    } else {
        name = group->strings[0];
    }
    DAT_002d836c = FUN_00198278(DAT_0034176c, name, 0x180, DAT_0033a060);

    if (DAT_0033a054 == 0) {
        name = DAT_002c0e20;
    } else if (DAT_0033a058->groupCount < 1) {
        name = DAT_002c0e1c;
    } else if ((group = DAT_0033a05c)->count < 2) {
        name = DAT_002c0e18;
    } else {
        name = group->strings[1];
    }
    DAT_002d8370 = FUN_00198278(DAT_0034176c, name, 0x180, DAT_0033a1e0);

    if (DAT_0033a054 == 0) {
        name = DAT_002c0e20;
    } else if (DAT_0033a058->groupCount < 1) {
        name = DAT_002c0e1c;
    } else if ((group = DAT_0033a05c)->count < 3) {
        name = DAT_002c0e18;
    } else {
        name = group->strings[2];
    }
    DAT_002d8374 = FUN_00198278(DAT_0034176c, name, 0x180, DAT_0033a360);

    if (DAT_0033a054 == 0) {
        name = DAT_002c0e20;
    } else if (DAT_0033a058->groupCount < 1) {
        name = DAT_002c0e1c;
    } else if ((group = DAT_0033a05c)->count < 4) {
        name = DAT_002c0e18;
    } else {
        name = group->strings[3];
    }
    DAT_002d8378 = FUN_00198278(DAT_0034176c, name, 0x180, DAT_0033a4e0);
}
