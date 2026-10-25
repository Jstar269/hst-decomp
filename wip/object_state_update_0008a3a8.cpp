/* HSTMATCH module=EBOOT.BIN start=0x0008a3a8 end=0x0008a634 symbol=FUN_0008a3a8 lang=c++ */

template <class T>
inline const T& min(const T& a, const T& b) {
    return b < a ? b : a;
}

struct InnerTarget {
    char pad[12];
    float field_12;
};

struct Obj {
    char pad_00[64];
    int field_64;
    int state;
    int field_72;
    char pad_76[32];
    int field_108;
};

extern int DAT_003386b4;
extern unsigned char DAT_003386b8;
extern const int DAT_002d2410;
extern const int DAT_002d2414;
extern const int DAT_002d240c;
extern const int DAT_002d2418;
extern InnerTarget *DAT_00331b84;
extern void *DAT_00331b88;
extern char *DAT_002cfc8c;
extern void *DAT_0034a138;

extern "C" void FUN_0006391c(void *, int, float);
extern "C" void FUN_0001f558(void *, int, int, int);
extern "C" void FUN_00063a30(void *, int, float);
extern "C" int FUN_001eca14(void *);
extern "C" int FUN_001ec9f8(void *);
extern "C" void FUN_0008ad40(void *);
extern "C" int FUN_0008add8(void *);
extern "C" void FUN_001ecbb0(void *);
extern "C" void FUN_00063d08(void *, int, float, float);

extern "C" void FUN_0008a3a8(Obj *self)
{
    switch (self->state) {
    case 0:
        self->field_72 = DAT_003386b4 = 0;
        self->state++;
        // fallthrough
    case 1:
        if (DAT_003386b4 >= DAT_002d2410) {
            FUN_0006391c(DAT_00331b84, 15, 65535.0f);
            self->state++;
        }
        break;
    case 2:
        if (DAT_00331b84->field_12 == 0.0f) {
            FUN_0001f558(self, 23, 0, 0);
            self->state++;
        }
        break;
    case 3:
        FUN_00063a30(DAT_00331b84, 15, 65535.0f);
        self->state++;
        break;
    case 4:
    default:
        break;
    }

    if (DAT_003386b8 != 0 && self->field_108 > 0) {
        self->field_108--;
    }

    DAT_003386b4 = min(DAT_003386b4 + 1, DAT_002d2414);

    if (!FUN_001eca14(DAT_0034a138)) {
        if ((self->field_72 >= DAT_002d240c && ((DAT_002cfc8c[139] << 28) >> 30) == 0 && FUN_001ec9f8(DAT_0034a138))
            || (DAT_003386b8 != 0 && self->field_108 <= 0)) {
            self->field_72 = -1;
        }
    }

    if (self->field_72 >= 0) {
        self->field_72 = min(self->field_72 + 1, DAT_002d2418);
    } else {
        FUN_0008ad40(self);
        if (FUN_0008add8(self)) {
            FUN_001ecbb0(DAT_0034a138);
            self->field_64 = 4;
            FUN_00063d08(DAT_00331b88, 15, 65535.0f, -1.0f);
        }
    }
}

// Differing words: 2/163 at +0x50.
// Retail:
//   0x8a3e8: beqzl v1, 0x8a3f8
//   0x8a3ec: lui v0, 0x34        (delay slot)
//   0x8a3f0: b 0x8a4b4
//   0x8a3f4: nop
//   0x8a3f8: sw zero, 72(s0)     (self->field_72 = 0)
//   0x8a3fc: sw zero, -31052(v0) (DAT_003386b4 = 0)
// Ours:
//   0x8a3e8: beqzl v1, 0x8a3f8
//   0x8a3ec: lui v0, 0x34        (delay slot)
//   0x8a3f0: b 0x8a4b4
//   0x8a3f4: nop
//   0x8a3f8: sw zero, -31052(v0)
//   0x8a3fc: sw zero, 72(s0)
// Ruled out:
// - DAT_003386b4 = 0; self->field_72 = 0; -> same 2 differing words at +0x50.
// - self->field_72 = 0; DAT_003386b4 = 0; -> delay slot hoists sw zero, 72(s0) instead of lui v0.
// - DAT_003386b4 = self->field_72 = 0; -> delay slot hoists sw zero, 72(s0).
// - Comma operators and reference bindings.
// near miss from lane ag5 (unreviewed)
