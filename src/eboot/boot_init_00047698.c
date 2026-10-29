/* HSTMATCH module=EBOOT.BIN start=0x00047698 end=0x0004784c symbol=FUN_00047698 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag from the fm11 near miss) corrected by hand: switch (0..3) for the allocation, DAT_003386b8 as unsigned char, DAT_00311054 as byte, end= trimmed to 0x4784c; exact match verified; names and types await human review. Matching idiom: the flag test and the two-way F call + store are written out in BOTH arms of the outer if (the else arm re-tests the same condition), which is what retail's duplicated blocks need. */
extern int DAT_00310fd0;
extern unsigned char DAT_003386b8;
extern int DAT_002d0220;
extern unsigned char DAT_00311054;
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
    unsigned char b1;

    FUN_0005b670(buf);
    FUN_0005ba78(DAT_003313c4, buf);
    FUN_0005ba00(buf, -1);
    switch (DAT_00310fd0) {
    case 0:
        p = FUN_00000bcc(0x48);
        if (p != 0)
            FUN_0008cb68(p);
        break;
    case 1:
        p = FUN_00000bcc(0xac);
        if (p != 0)
            FUN_00088258(p);
        break;
    case 2:
        FUN_002863e4();
        p = FUN_00000bcc(400);
        if (p != 0)
            FUN_001c3bac(p);
        break;
    case 3:
        break;
    }
    DAT_002d0220 = DAT_00310fd0;
    if (((DAT_00310fd0 == 1) && (DAT_003386b8 == 0)) || (DAT_00310fd0 == 2)) {
        b1 = 1;
        if ((DAT_00310fd0 == 1) && (DAT_003386b8 != 0))
            b1 = 0;
        if (b1) {
            FUN_002b7d40(0x14d, 0x14d, 0xa6);
        } else {
            FUN_002b7d40(0xde, 0xde, 0x6f);
        }
        DAT_00311054 = b1;
    } else {
        b1 = 0;
        if ((DAT_00310fd0 == 1) && (DAT_003386b8 != 0))
            b1 = 0;
        if (b1) {
            FUN_002b7d40(0x14d, 0x14d, 0xa6);
        } else {
            FUN_002b7d40(0xde, 0xde, 0x6f);
        }
        DAT_00311054 = b1;
    }
    FUN_00061e7c();
}
