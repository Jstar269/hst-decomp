/* HSTMATCH module=EBOOT.BIN start=0x0001bc6c end=0x0001be84 symbol=FUN_0001bc6c lang=c99 */
extern int DAT_0030ebd8;
extern int DAT_0030ebd4;
extern char DAT_002cfb28, DAT_002cfb3c, DAT_002cfbf8, DAT_002cfbe8, DAT_002cfbd4;
extern char DAT_002cfb68, DAT_002cfbc0, DAT_002cfbb0, DAT_002cfba4, DAT_002cfb8c;
extern char DAT_002cfb7c, DAT_002cfb58, DAT_002cfb48;

extern void FUN_000143b0(void *, const char *, const char *, int);
extern int FUN_002b7990(void);
extern int FUN_002b7920(void *, void *, int, int, int, int);
extern void FUN_0001bc3c(void);
extern void FUN_0001b918(const char *, ...);
extern int FUN_002b78d8(int, int, int);

void FUN_0001bc6c(void)
{
    char buf[64];
    int r;

    DAT_0030ebd8 = 0;
    FUN_000143b0(buf, &DAT_002cfb28, &DAT_002cfb3c, 0xd5);
    r = FUN_002b7990();
    DAT_0030ebd4 = FUN_002b7920(buf, (void *)FUN_0001bc3c, r - 1, 0x4000, 0, 0);
    if (DAT_0030ebd4 < 1) {
        if (DAT_0030ebd4 == -0x7ffdfe47)
            FUN_0001b918(&DAT_002cfbf8);
        else if (DAT_0030ebd4 == -0x7ffdfe6e)
            FUN_0001b918(&DAT_002cfbe8);
        else if (DAT_0030ebd4 == -0x7ffdfe6d)
            FUN_0001b918(&DAT_002cfbd4);
        else if (DAT_0030ebd4 == -0x7ffdff9c)
            FUN_0001b918(&DAT_002cfb68);
        else if (DAT_0030ebd4 == -0x7ffdfe6c)
            FUN_0001b918(&DAT_002cfbc0);
        else if (DAT_0030ebd4 == -0x7ffdfe6f)
            FUN_0001b918(&DAT_002cfbb0);
        else if (DAT_0030ebd4 == -0x7ffdfe70)
            FUN_0001b918(&DAT_002cfba4);
        else
            FUN_0001b918(&DAT_002cfb8c, &DAT_002cfb3c, 0x110);
        for (;;)
            ;
    }
    r = FUN_002b78d8(DAT_0030ebd4, 0, 0);
    if (r == 0)
        return;
    if (r == -0x7ffdfe5c)
        FUN_0001b918(&DAT_002cfb7c);
    else if (r == -0x7ffdff9c)
        FUN_0001b918(&DAT_002cfb68);
    else if (r == -0x7ffdfe69)
        FUN_0001b918(&DAT_002cfb58);
    else if (r == -0x7ffdfe68)
        FUN_0001b918(&DAT_002cfb48);
    else
        FUN_0001b918(&DAT_002cfb8c, &DAT_002cfb3c, 0xf0);
    for (;;)
        ;
}
// near miss from lane fm11 (unreviewed)
