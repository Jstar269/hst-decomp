/* HSTMATCH module=EBOOT.BIN start=0x001affe4 end=0x001b0130 symbol=FUN_001affe4 lang=c99 data=0x002e9598 */
/* Hand-written reconstruction from the disassembly; exact match verified (83/83 words).
   Court-sound/BGM start: tears down the three sub-entries at 0x79c+0xe/0x5c/0x70, allocates
   the 0x100000-byte buffer, loads 0x002e9598 into the 0x30ebf4 sound bank, starts the three
   entries (only the first gets the optional BGM name from DAT_002c5a64 when param_3 bit 0 is
   set), records param_2 and frees the buffer. Names and types await human review. Data: its string literals (1 strings, 0x002e9598-0x002e95b8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern char DAT_0030ab9c[];
extern char DAT_0030ebf4[];
extern char *DAT_002c5a64;
extern int FUN_00010184(int, int);
extern void FUN_0001bfb4(char *, int, int);
extern int FUN_0001ca58(char *, char *, int);
extern void FUN_001b04d0(int, int);
extern void FUN_001b0ef8(int, int, int, int, char *);
extern void FUN_0001cb88(char *);
extern int FUN_0001cbfc(void);
extern int FUN_0001cc54(void);
extern void FUN_000104e0(int);

void FUN_001affe4(int param_1, int param_2, unsigned param_3)
{
    int buf;
    char *bgm;
    int a;
    int b;

    if (*(int *)(param_1 + 0x79c) >= 0) {
        FUN_001b04d0(param_1, *(int *)(param_1 + 0x79c) + 0xe);
        FUN_001b04d0(param_1, *(int *)(param_1 + 0x79c) + 0x5c);
        FUN_001b04d0(param_1, *(int *)(param_1 + 0x79c) + 0x70);
        *(int *)(param_1 + 0x79c) = -1;
    }
    buf = FUN_00010184(0x40, 0x100000);
    FUN_0001bfb4(DAT_0030ab9c, buf, 0x100000);
    FUN_0001ca58(DAT_0030ebf4, "game/900_sound/020_court%02d.xb", param_2 + 1);
    bgm = 0;
    if ((param_3 & 1) != 0)
        bgm = DAT_002c5a64;
    FUN_001b0ef8(param_1, param_2 + 0xe, 0, 0, bgm);
    FUN_001b0ef8(param_1, param_2 + 0x5c, 0, 0, 0);
    *(int *)(param_1 + 0x7c0) = param_2 + 0x70;
    FUN_001b0ef8(param_1, param_2 + 0x70, 0, 0, 0);
    *(int *)(param_1 + 0x79c) = param_2;
    FUN_0001cb88(DAT_0030ebf4);
    a = FUN_0001cbfc();
    b = FUN_0001cc54();
    FUN_0001bfb4(DAT_0030ab9c, a, b);
    FUN_000104e0(buf);
}
