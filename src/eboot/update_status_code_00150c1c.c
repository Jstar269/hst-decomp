/* HSTMATCH module=EBOOT.BIN start=0x00150c1c end=0x00150cdc symbol=FUN_00150c1c lang=c99 data=0x002dc444 */
/* Clone of src/sharing_main/update_status_code_0015cc54.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc444-0x002dc45a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct {
    char pad[8];
    int f8;
} Param1;

typedef struct {
    char pad[0x34];
    int f34;
    int f38;
    char pad2[0x5c - 0x3c];
    u8 f5c;
} Sub;

typedef struct {
    void *target;
    char pad[8];
    Sub *sub;
} Param2;

extern u8 DAT_003402f0;
extern int *FUN_0014c384(void *target, int f8);
extern void FUN_0014d044(Param2 *param_2);
extern void FUN_0014fd94(char *buf, int f8);
extern int FUN_0022ada4(int a, int b);
extern int FUN_0022ae88(int a, int b);

int FUN_00150c1c(Param1 *param_1, Param2 *param_2)
{
    if (DAT_003402f0 != 0) {
        FUN_0014d044(param_2);
        FUN_0014fd94("MatchRecord [reg:%d]\n", param_1->f8);
    }
    Sub *sub = param_2->sub;
    void *target = param_2->target;
    int code = 0;
    if (FUN_0022ada4(sub->f34, sub->f38)) {
        code = 1;
    } else if (FUN_0022ae88(sub->f34, sub->f38)) {
        code = 2;
    }
    if (sub->f5c != 0) {
        code = 0;
    }
    int *res = FUN_0014c384(target, param_1->f8);
    *res = code;
    return 0;
}
