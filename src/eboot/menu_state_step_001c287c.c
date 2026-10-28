/* HSTMATCH module=EBOOT.BIN start=0x001c287c end=0x001c2ac0 symbol=FUN_001c287c lang=c99 rodata=0x2c63ac */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/menu_state.h"

extern int DAT_0034a2e0;
extern int DAT_003415d4;
extern char DAT_0034179c;
extern int FUN_0021ab8c(StateSrc *);
extern int FUN_001c7158(void);
extern int FUN_002afb80(void *, int);
extern void FUN_001cd88c(MenuState *, int, int);
extern void FUN_001c2498(MenuState *);
extern void FUN_00225d98(int);
extern void FUN_001c9d7c(void *);
extern void FUN_001c9dec(void *);
extern void FUN_001c9dfc(void *);
extern void FUN_001c9e0c(void *);
extern void FUN_001ca8e8(void *);
extern void FUN_001ca8f0(void *);
extern void FUN_001905b8(int, int);
extern void FUN_001cd3d8(void *);
extern void FUN_001b4848(float, void *);
extern void FUN_001b2430(void *);

/* State handler: reads the chosen action id from the source object (0 confirm, 1-6 and 9 pick an entry,
   7 and 8 ignored) and starts the matching flow. */
void FUN_001c287c(MenuState *self)
{
    int action;
    int result;

    action = FUN_0021ab8c(self->src);
    switch (action) {
    case 0:
        result = FUN_001c7158();
        if (result != 0) {
            result = FUN_002afb80(self->parent, 0);
            if (result != 0) {
                FUN_001cd88c(self, 5, 1);
                FUN_001c2498(self);
                FUN_00225d98(DAT_0034a2e0);
            }
        }
        break;
    case 1:
        FUN_001cd88c(self, 0, 1);
        FUN_001c9d7c(self->parent);
        break;
    case 2:
        FUN_001cd88c(self, 0, 1);
        FUN_001c9dec(self->parent);
        break;
    case 3:
        FUN_001cd88c(self, 0, 1);
        FUN_001c9dfc(self->parent);
        break;
    case 4:
        FUN_001cd88c(self, 0, 1);
        FUN_001c9e0c(self->parent);
        break;
    case 9:
        FUN_001ca8e8(self->parent);
        self->unke8 = 0;
        self->unkf0 = 0;
        FUN_001905b8(DAT_003415d4, 3);
        FUN_001cd88c(self, 8, 1);
        FUN_001cd3d8(self->parent);
        break;
    case 5:
        FUN_001ca8e8(self->parent);
        self->unke8 = 2;
        self->unkf0 = 0;
        FUN_001905b8(DAT_003415d4, 3);
        FUN_001cd88c(self, 8, 1);
        FUN_001cd3d8(self->parent);
        break;
    case 6:
        FUN_001ca8f0(self->parent);
        self->unke8 = 1;
        self->unkf0 = 0;
        FUN_001905b8(DAT_003415d4, 3);
        FUN_001cd88c(self, 8, 1);
        FUN_001cd3d8(self->parent);
        break;
    case 7:
    case 8:
        break;
    default:
        break;
    }
    result = self->unk10;
    if (result == 0) {
        FUN_001b4848(0.1f, &DAT_0034179c);
        FUN_001b2430(&DAT_0034179c);
    }
    if (self->src->state == 0xb && self->unk10 != 8) {
        FUN_001cd88c(self, 0, 1);
    }
}
