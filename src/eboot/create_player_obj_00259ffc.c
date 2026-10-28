/* HSTMATCH module=EBOOT.BIN start=0x00259ffc end=0x0025a0e8 symbol=FUN_00259ffc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: reconstructed player string branch, decrement condition, and if ((puVar2 = alloc())) pattern; exact match verified; names and types await human review. */

#include "hst/types.h"

extern u8 DAT_002bc410;
extern u8 DAT_0030779c;
extern char DAT_002ca7d4[];
extern char DAT_002ca7e0[];
extern void *FUN_00000bcc(int);
extern int FUN_00014934(int, const char *);
extern u32 FUN_00056098(void *);
extern u32 *FUN_000fbf84(void *, void *);
extern u32 *FUN_000fc00c(void *, void *);
extern u32 *FUN_000fc0a0(void *);

u32 *FUN_00259ffc(int param_1, int param_2, char *param_3)
{
    const char *str;
    if (*(unsigned char *)(param_1 + 0x644) != '\0') {
        str = DAT_002ca7e0;
    } else {
        str = DAT_002ca7d4;
    }

    if (FUN_00014934(param_2, str) == 0) {
        int val = *(int *)(param_1 + 0x648);
        *(int *)(param_1 + 0x648) = val - 1;
        *param_3 = 0 < val;
    } else {
        *param_3 = 0;
    }

    u32 *puVar2;
    if ((puVar2 = (u32 *)FUN_00000bcc(0xd0)) != 0) {
        FUN_000fc0a0(puVar2);
        FUN_00056098(puVar2 + 0xc);
        *puVar2 = (unsigned int)&DAT_0030779c;
        puVar2[0x1c] = 0;
        puVar2[0x1d] = 0xffffffff;
        puVar2[0x1e] = 0x3f800000;
        puVar2[0x1f] = 0x3f800000;
        FUN_00056098(puVar2 + 0x20);
        puVar2[0x30] = param_2;
        FUN_000fc00c(puVar2, &DAT_002bc410);
        FUN_000fbf84(puVar2 + 0x20, &DAT_002bc410);
    }
    return puVar2;
}
