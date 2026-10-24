/* HSTMATCH module=EBOOT.BIN start=0x00174040 end=0x00174260 symbol=FUN_00174040 lang=c99 */
#pragma opt_strength_reduction off

typedef unsigned int uint;

extern char DAT_0034179c;

int FUN_00179560(void *self, int mode);
int FUN_0017947c(void *self, int f5cc, int f5d0);
int FUN_0017951c(void *self, int mode);
void FUN_00185970(int f174, int mode, int f5cc, int f5d0, int f5d8, int res, int f5d4, int t3, int res_560, int one);
void FUN_001b1c44(void *dat, int six);
void FUN_0017cfb4(int f178, int val);

struct Entry {
    int f5cc;
    int f5d0;
    int f5d4;
    int f5d8;
    int pad;
};

struct Obj {
    char pad0[372];
    int f174;
    int f178;
    char pad1[1084];
    int mode; // 1464 (0x5b8)
    int pad2; // 1468
    int *f5c0; // 1472 (0x5c0)
    uint f5c4;  // 1476 (0x5c4)
    int pad3; // 1480
    struct Entry entries[5]; // 1484 (0x5cc)
};

int FUN_00174040(struct Obj *self, int dir, int wrap, int flag, int new_mode) {
    int old_mode = self->mode;

    if (new_mode != 0x7fffffff) {
        self->mode = new_mode;
        old_mode = 0x7fffffff;
        goto join;
    }

    if (dir > 0) {
        new_mode = old_mode + 1;
        if (!((uint)new_mode < self->f5c4)) {
            if (wrap == 0) {
                old_mode = self->mode;
                goto join_check;
            }
            self->mode = 0;
            goto join;
        } else {
            for (;;) {
                if ((uint)new_mode >= self->f5c4) {
                    self->mode = 0;
                    break;
                }
                if (self->f5c0[new_mode] != 0x7fffffff) {
                    self->mode = new_mode;
                    break;
                }
                new_mode++;
            }
        }
    } else if (dir < 0) {
        flag = old_mode - 1;
        if (!(flag >= 0)) {
            if (wrap == 0) {
                goto join;
            }
            self->mode = self->f5c4 - 1;
            goto join;
        } else {
            for (;;) {
                if (flag < 0) {
                    self->mode = 0;
                    break;
                }
                if (self->f5c0[flag] != 0x7fffffff) {
                    self->mode = flag;
                    break;
                }
                flag--;
            }
        }
    }

join:
join_check:
    if (old_mode == self->mode) {
        return 0;
    }

    int res_560 = FUN_00179560(self, self->mode);
    if (flag != 0) {
        int res = FUN_0017947c(self, self->entries[self->mode].f5cc, self->entries[self->mode].f5d0);
        FUN_00185970(self->f174, self->mode, self->entries[self->mode].f5cc, self->entries[self->mode].f5d0,
                     self->entries[self->mode].f5d8, res, self->entries[self->mode].f5d4, 0, res_560, 1);
    } else {
        int res = FUN_0017951c(self, self->mode);
        FUN_00185970(self->f174, self->mode, self->entries[self->mode].f5cc, self->entries[self->mode].f5d0,
                     self->entries[self->mode].f5d8, res, self->entries[self->mode].f5d4, 1, res_560, 1);
    }

    FUN_001b1c44(&DAT_0034179c, 6);
    if (self->mode == 4) {
        FUN_0017cfb4(self->f178, 3);
    } else {
        FUN_0017cfb4(self->f178, 1);
    }
    return 1;
}
// NEAR (136/136 words; 61 differ). Frame size (32 bytes) and exact word count matched.
// Sibling of src/eboot/update_mode_entries_001744b0.c and wip/menu_option_toggle_00174260.c.
// Loops and all call setups match; differences remain in register coloring of 0x7fffffff sentinel ($t1 vs $a3) and $v0=0 early return slot.
// near miss from lane ag4 (unreviewed)
