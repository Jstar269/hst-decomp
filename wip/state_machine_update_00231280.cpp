/* HSTMATCH module=EBOOT.BIN start=0x00231280 end=0x00231390 symbol=FUN_00231280 lang=c++ rodata=0x002c9c44 */

extern char *DAT_002cfc8c;
extern int DAT_0034179c;

extern "C" void FUN_0022e64c();
extern "C" void FUN_0022ffe4(void *);
extern "C" void FUN_001b1c44(void *, int);

struct Inner {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();

    char pad_04[80];
    unsigned char field_84;
    char pad_55[959];
    int field_1044;
};

struct Outer {
    Inner *inner;
    int field_4;
};

extern "C" void FUN_00231280(Outer *self)
{
    if (self->field_4 == 1) {
        return;
    }
    if ((DAT_002cfc8c[139] << 26) >> 30) {
        self->inner->vfunc2();
    } else {
        int flag;
        switch (self->inner->field_1044) {
        case 0:
        case 3:
        case 4:
            flag = 1;
            break;
        case 1:
        case 2:
        case 5:
        case 6:
        case 7:
        case 8:
            flag = 0;
            break;
        default:
            flag = 1;
            break;
        }

        if (flag == 0 || self->field_4 != 0) {
            self->inner->vfunc2();
        } else {
            FUN_0022e64c();
            FUN_0022ffe4(self->inner);

            int v = 1;
            if (self->inner->field_84 != 0) {
                FUN_001b1c44(&DAT_0034179c, 4);
                v = 1;
            }
            self->field_4 = v;
            if (v == 0) {
                self->inner->vfunc1();
            }
        }
    }
}

// Differing words: 59 / 68
// Ruled out:
// - Outer enclosing `if (!((...)))`: forces premature `move s0, a0` at entry before `self->field_4` check.
// - Explicit `goto tail`: forces clobbering of `a0` and destroys the entry argument register scheduling.
// - Volatile local: spills to stack, increasing stack frame from 16 to 32 bytes.
// Remaining differences:
// - Retail shares the `self->inner->vfunc2()` tail call at 0x231370 across both the bitfield test and flag check,
//   whereas MWCC emits a duplicate inline call at 0x2312bc for the first check.
// - Retail keeps `flag` in `v0` (reusing `v0` from `lw v0, 1044(a0)`), while MWCC allocates `a2` for `flag`.
// near miss from lane ag5 (unreviewed)
