/* HSTMATCH module=EBOOT.BIN start=0x00296ff8 end=0x00297188 symbol=FUN_00296ff8 lang=c99 */

extern char DAT_002cb350;
extern char DAT_0034a860;
extern int DAT_0034ac60;
extern int DAT_0034ac64;
extern int DAT_0034ac6c;
extern char DAT_002cb354[];

extern void FUN_002969e0(char *dst, const char *src, int maxlen);
extern void FUN_00296a84(char *dst, const char *src, int maxlen);
extern int FUN_00297188(void);
extern void FUN_002982c8(void);
extern int FUN_00298e4c(void);
extern int FUN_00299790(char *buf);
extern int FUN_00299988(char *buf, void *param_2, int flag);
extern void FUN_002b78f0(void);
extern int FUN_002b79f8(int flag);
extern int FUN_002b7a10(int flag);

int FUN_00296ff8(void)
{
    char stack_480[4];
    int local_47c;
    char buf[1024];
    int res = 0;
    int unused = 0;

    if (DAT_0034ac6c != 2) {
        res = -0x7ffffffd;
        goto cleanup;
    }

    FUN_002b78f0();
    if (DAT_0034ac64 != 0 && DAT_0034ac60 == 0) {
        res = -0x7ffffffc;
        goto cleanup;
    }

    res = FUN_002b7a10(0);
    if (res < 0) {
        goto cleanup;
    }

    if (DAT_0034ac60 == 0) {
load_sfo:
        FUN_002969e0(buf, &DAT_0034a860, 0x400);
        FUN_00296a84(buf, &DAT_002cb350, 0x400);
        FUN_00296a84(buf, DAT_002cb354, 0x400);
        local_47c = 0;
        FUN_00299988(buf, stack_480, 2);
        res = FUN_00299790(buf);
    } else {
        res = FUN_00298e4c();
        if (res == 0) {
            DAT_0034ac60 = 0;
            res = 0;
            goto load_sfo;
        }
    }

    unused = FUN_002b79f8(0);

cleanup:
    if (res < 0) {
        FUN_00297188();
    } else {
        FUN_002982c8();
    }
    DAT_0034ac6c = 1;
    return res;
}

// Sony SDK (sceUtility savedata PARAM.SFO loader).
// Retail code is GCC at -O0: 1152-byte stack frame, s8 frame pointer (`move s8, sp`),
// every local homed on stack (`local_47c` at 4(s8), `buf` at 96(s8), `res` at 1120(s8),
// `unused` at 1124(s8)), and absolute `j` jumps with nop delay slots.
// Under mwcc219 -O4,p locals are assigned to registers and frame is 1056 bytes.
// near miss from lane ag3 (unreviewed)
