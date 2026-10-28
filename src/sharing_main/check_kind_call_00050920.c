/* HSTMATCH module=hstp_trans_main.prx start=0x00050920 end=0x00050988 symbol=FUN_00050920 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct {
    char pad[0x18];
    void *ptr;
    char pad2[0x8c - 0x1c];
    u8 kind;
} Obj;

extern Obj *FUN_00050aec(void);
extern int FUN_00023ac8(void *p, int param_3, int param_3_zero);

int FUN_00050920(int param_1, int param_2, int param_3)
{
    int res = 0;
    Obj *obj = FUN_00050aec();
    if (obj != 0) {
        void *p = (obj->kind == 3) ? obj->ptr : 0;
        if (p != 0) {
            res = FUN_00023ac8(p, param_3, 0);
        }
    }
    return res;
}
