/* HSTMATCH module=hstp_trans_main.prx start=0x0015cc54 end=0x0015cd14 symbol=FUN_0015cc54 lang=c99 data=0x0038392c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0038392c-0x00383942) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef unsigned char uchar;

typedef struct {
    char pad[8];
    int f8;
} Param1;

typedef struct {
    char pad[0x34];
    int f34;
    int f38;
    char pad2[0x5c - 0x3c];
    uchar f5c;
} Sub;

typedef struct {
    void *target;
    char pad[8];
    Sub *sub;
} Param2;

extern uchar DAT_003e9630;
extern int *FUN_00157e10(void *target, int f8);
extern void FUN_00158b2c(Param2 *param_2);
extern void FUN_0015bb68(char *buf, int f8);
extern int FUN_0023a6f8(int a, int b);
extern int FUN_0023a750(int a, int b);

int FUN_0015cc54(Param1 *param_1, Param2 *param_2)
{
    if (DAT_003e9630 != 0) {
        FUN_00158b2c(param_2);
        FUN_0015bb68("MatchRecord [reg:%d]\n", param_1->f8);
    }
    Sub *sub = param_2->sub;
    void *target = param_2->target;
    int code = 0;
    if (FUN_0023a6f8(sub->f34, sub->f38)) {
        code = 1;
    } else if (FUN_0023a750(sub->f34, sub->f38)) {
        code = 2;
    }
    if (sub->f5c != 0) {
        code = 0;
    }
    int *res = FUN_00157e10(target, param_1->f8);
    *res = code;
    return 0;
}
