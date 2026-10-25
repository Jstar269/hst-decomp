/* HSTMATCH module=EBOOT.BIN start=0x00047698 end=0x00047850 symbol=FUN_00047698 lang=c99 */
extern int DAT_00310fd0;
extern char DAT_003386b8;
extern int DAT_002d0220;
extern int DAT_00311054;
extern int DAT_003313c4;

extern void FUN_0005b670(void *);
extern void FUN_0005ba78(int, void *);
extern void FUN_0005ba00(void *, int);
extern void FUN_002863e4(void);
extern void *FUN_00000bcc(unsigned int);
extern void FUN_001c3bac(void *);
extern void FUN_00088258(void *);
extern void FUN_0008cb68(void *);
extern void FUN_002b7d40(int, int, int);
extern void FUN_00061e7c(void);

void FUN_00047698(void)
{
    char buf[704];
    void *p;
    int b1;

    FUN_0005b670(buf);
    FUN_0005ba78(DAT_003313c4, buf);
    FUN_0005ba00(buf, -1);
    if (DAT_00310fd0 != 3) {
        if (DAT_00310fd0 == 2) {
            FUN_002863e4();
            p = FUN_00000bcc(400);
            if (p != 0)
                FUN_001c3bac(p);
        } else if (DAT_00310fd0 == 1) {
            p = FUN_00000bcc(0xac);
            if (p != 0)
                FUN_00088258(p);
        } else if (DAT_00310fd0 == 0) {
            p = FUN_00000bcc(0x48);
            if (p != 0)
                FUN_0008cb68(p);
        }
    }
    DAT_002d0220 = DAT_00310fd0;
    if (((DAT_00310fd0 == 1) && (DAT_003386b8 == 0)) || (DAT_00310fd0 == 2)) {
        b1 = 1;
        if ((DAT_00310fd0 == 1) && (DAT_003386b8 != 0))
            b1 = 0;
        if (b1) {
            FUN_002b7d40(0x14d, 0x14d, 0xa6);
            DAT_00311054 = b1;
        } else {
            FUN_002b7d40(0xde, 0xde, 0x6f);
            DAT_00311054 = b1;
        }
    } else {
        FUN_002b7d40(0xde, 0xde, 0x6f);
        DAT_00311054 = 0;
    }
    FUN_00061e7c();
}
// near miss from lane fm11 (unreviewed)
