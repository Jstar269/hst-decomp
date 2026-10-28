/* HSTMATCH module=EBOOT.BIN start=0x0016fd08 end=0x0016fd94 symbol=FUN_0016fd08 lang=c99 */
/* Clone of src/sharing_main/reset_mode_entries_0017bf54.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Obj Obj;
typedef void *(*GetFn)(int);

struct Obj {
    char pad[0x46];
    u8 flag;
    char pad1;
    int mode;
    char pad2[0x8c - 0x4c];
    int val_8c;
    char pad3[0x3e8 - 0x90];
    GetFn get;
};

void FUN_0016fd08(Obj *self)
{
    if (self->flag == 0) {
        return;
    }
    switch (self->mode) {
    case 1:
        self->val_8c = 0;
        break;
    case 2:
        self->val_8c = 14;
        break;
    case 3:
        self->val_8c = 29;
        break;
    }
    int i = 0;
    do {
        short *p = (short *)self->get(i);
        i++;
        p[1] = 0;
    } while (i < 15);
}
