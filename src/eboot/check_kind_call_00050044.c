/* HSTMATCH module=EBOOT.BIN start=0x00050044 end=0x000500ac symbol=FUN_00050044 lang=c99 */
/* Clone of src/sharing_main/check_kind_call_00050920.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct {
    char pad[0x18];
    void *ptr;
    char pad2[0x8c - 0x1c];
    u8 kind;
} Obj;

extern Obj *FUN_00050210(void);
extern int FUN_00023aa0(void *p, int param_3, int param_3_zero);

int FUN_00050044(int param_1, int param_2, int param_3)
{
    int res = 0;
    Obj *obj = FUN_00050210();
    if (obj != 0) {
        void *p = (obj->kind == 3) ? obj->ptr : 0;
        if (p != 0) {
            res = FUN_00023aa0(p, param_3, 0);
        }
    }
    return res;
}
