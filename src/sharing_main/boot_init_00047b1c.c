/* HSTMATCH module=hstp_trans_main.prx start=0x00047b1c end=0x00047cd0 symbol=FUN_00047b1c lang=c99 */
/* Clone of src/eboot/boot_init_00047698.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag from the fm11 near miss) corrected by hand: switch (0..3) for the allocation, DAT_003e19f8 as unsigned char, DAT_003ba37c as byte, end= trimmed to 0x4784c; exact match verified; names and types await human review. Matching idiom: the flag test and the two-way F call + store are written out in BOTH arms of the outer if (the else arm re-tests the same condition), which is what retail's duplicated blocks need. */
extern int DAT_003ba2d0;
extern unsigned char DAT_003e19f8;
extern int DAT_00375968;
extern unsigned char DAT_003ba37c;
extern int DAT_003da704;

extern void FUN_0005c2f8(void *);
extern void FUN_0005c700(int, void *);
extern void FUN_0005c688(void *, int);
extern void FUN_00297ab4(void);
extern void *FUN_00000bcc(unsigned int);
extern void FUN_001d1f38(void *);
extern void FUN_000898e8(void *);
extern void FUN_0008e2b0(void *);
extern void FUN_002c7ac8(int, int, int);
extern void FUN_00062d00(void);

void FUN_00047b1c(void)
{
    char buf[704];
    void *p;
    unsigned char b1;

    FUN_0005c2f8(buf);
    FUN_0005c700(DAT_003da704, buf);
    FUN_0005c688(buf, -1);
    switch (DAT_003ba2d0) {
    case 0:
        p = FUN_00000bcc(0x48);
        if (p != 0)
            FUN_0008e2b0(p);
        break;
    case 1:
        p = FUN_00000bcc(0xac);
        if (p != 0)
            FUN_000898e8(p);
        break;
    case 2:
        FUN_00297ab4();
        p = FUN_00000bcc(400);
        if (p != 0)
            FUN_001d1f38(p);
        break;
    case 3:
        break;
    }
    DAT_00375968 = DAT_003ba2d0;
    if (((DAT_003ba2d0 == 1) && (DAT_003e19f8 == 0)) || (DAT_003ba2d0 == 2)) {
        b1 = 1;
        if ((DAT_003ba2d0 == 1) && (DAT_003e19f8 != 0))
            b1 = 0;
        if (b1) {
            FUN_002c7ac8(0x14d, 0x14d, 0xa6);
        } else {
            FUN_002c7ac8(0xde, 0xde, 0x6f);
        }
        DAT_003ba37c = b1;
    } else {
        b1 = 0;
        if ((DAT_003ba2d0 == 1) && (DAT_003e19f8 != 0))
            b1 = 0;
        if (b1) {
            FUN_002c7ac8(0x14d, 0x14d, 0xa6);
        } else {
            FUN_002c7ac8(0xde, 0xde, 0x6f);
        }
        DAT_003ba37c = b1;
    }
    FUN_00062d00();
}
