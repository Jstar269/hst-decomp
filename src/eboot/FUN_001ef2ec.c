/* HSTMATCH module=EBOOT.BIN start=0x001ef2ec end=0x001ef3f8 symbol=FUN_001ef2ec lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern char DAT_002ee7d0[];
extern char DAT_002ee7d8[];
extern int DAT_00310fc4;
extern int DAT_0034b5d0;
extern void FUN_00000020(char *);
extern void FUN_001ef3f8(char *);
extern void FUN_000429a0(int);
extern void FUN_00042698(int, int, int);
extern int FUN_00000bcc(int);
extern int FUN_00218c00(int);
extern void FUN_001f2954(int);
extern void FUN_001f898c(int);
extern void FUN_001fb928(int, int, int);
extern void FUN_001fb9dc(int);
extern void FUN_001ef424(int);
extern void FUN_001ff668(void);
extern void FUN_002adfc4(int);
extern void FUN_00000028(void);

void FUN_001ef2ec(int param_1)
{
    int v;

    FUN_00000020(DAT_002ee7d0);
    FUN_001ef3f8(DAT_002ee7d8);
    FUN_000429a0(DAT_00310fc4);
    FUN_00042698(DAT_00310fc4, 0x200, 0x100);
    *(char *)(param_1 + 0x515) = 0;
    *(char *)(param_1 + 0x516) = 0;
    *(char *)(param_1 + 0x517) = 0;
    *(int *)((char *)param_1 + 0x817c) = 0;
    *(char *)((char *)param_1 + 0x8198) = 0;
    *(int *)(param_1 + 0x558) = 0;
    *(int *)(param_1 + 0x3e8) = 0;
    *(int *)(param_1 + 0x3f8) = 0;
    *(int *)(param_1 + 0x3ec) = 0;
    *(int *)(param_1 + 0x3fc) = 0;
    *(int *)(param_1 + 0x3f0) = 0;
    *(int *)(param_1 + 0x400) = 0;
    *(int *)(param_1 + 0x3f4) = 0;
    *(int *)(param_1 + 0x404) = 0;
    *(char *)(param_1 + 0x520) = 0;
    v = FUN_00000bcc(0x20);
    if (v != 0)
        v = FUN_00218c00(v);
    *(int *)(param_1 + 0x564) = v;
    FUN_001f2954(param_1);
    FUN_001f898c(param_1);
    FUN_001fb928(param_1 + 0x3c, 1, 1);
    FUN_001fb9dc(param_1 + 0x3c);
    FUN_001ef424(param_1);
    FUN_001ff668();
    FUN_002adfc4(DAT_0034b5d0);
    FUN_00000028();
}
