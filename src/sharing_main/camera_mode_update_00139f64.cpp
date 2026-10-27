/* HSTMATCH module=hstp_trans_main.prx start=0x00139f64 end=0x0013a348 symbol=FUN_00139f64 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Camera mode update (mode global DAT_003e48b8): mode 0 nudges the float at +0xe8 by two 2-bit pad fields, resets
   the camera globals (DAT_00381f44 is the value build_basis copies into the basis' angle slot) and clamps +0xe8;
   modes 3/4 clamp the globals into their [lo, hi] pairs. Matching idioms: the "neither field pressed" test is the
   inline THEN arm (inverted condition), the bounds go through a const& Clamp (retail reloads them), and retail's
   dead `else if (mode == 3)` arm after the 3/4 test is kept. */
struct Pad {                /* DAT_003751d4 */
    char pad0[0x8a];
    signed char a0 : 2;     /* 0x8a bits 0-1 */
    signed char a1 : 2;     /* 0x8a bits 2-3 */
    signed char a2 : 2;
    signed char a3 : 2;
};

struct CamObj;

struct Obj {
    char pad[0xe0];
    CamObj *obj;
    unsigned char fe4;
    float fe8;
    unsigned char fec;
};

extern Pad *DAT_003751d4;
extern int DAT_003da704;
extern int DAT_003e48b8;
extern float DAT_003e48bc;
extern float DAT_00381f44;
extern float DAT_00381f50;
extern float DAT_00381f54;
extern float DAT_00381f5c;
extern float DAT_00381fb4;
extern float DAT_00381fb8;
extern float DAT_00381fbc;
extern float DAT_00381fc0;
extern float DAT_00381fc4;
extern float DAT_00381fc8;
extern float DAT_00381fcc;
extern float DAT_00381fd0;

extern "C" void FUN_00062160(CamObj *, int);
extern "C" void FUN_0013a7a0(Obj *);

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" void FUN_00139f64(Obj *self)
{
    if (DAT_003e48b8 == 0) {
        if (DAT_003751d4->a1 != 1 && DAT_003751d4->a0 != 1) {
            self->fec = 0;
        } else {
            if (DAT_003751d4->a1 == 1 && DAT_003751d4->a0 == 1) {
                self->fe8 += -self->fe8 * 0.3f;
                self->fec = 1;
            } else if (DAT_003751d4->a1 == 1 && self->fec == 0) {
                self->fe8 -= 2.0f;
            } else if (DAT_003751d4->a0 == 1 && self->fec == 0) {
                self->fe8 += 2.0f;
            }
        }
        DAT_00381f44 = 40.0f;
        DAT_00381f50 = 19.8f;
        DAT_00381f54 = 35.0f;
        DAT_003e48bc = 0.0f;
        DAT_00381f5c = 20.0f;
        self->fe8 = Clamp(self->fe8, -DAT_00381f5c, DAT_00381f5c);
        FUN_0013a7a0(self);
    } else if (DAT_003e48b8 == 3 || DAT_003e48b8 == 4) {
        DAT_00381f44 = Clamp(DAT_00381f44, DAT_00381fb4, DAT_00381fb8);
        DAT_00381f50 = Clamp(DAT_00381f50, DAT_00381fbc, DAT_00381fc0);
        DAT_00381f54 = Clamp(DAT_00381f54, DAT_00381fc4, DAT_00381fc8);
        DAT_003e48bc = Clamp(DAT_003e48bc, DAT_00381fcc, DAT_00381fd0);
        self->fe8 = Clamp(self->fe8, -DAT_00381f5c, DAT_00381f5c);
        FUN_0013a7a0(self);
    } else if (DAT_003e48b8 == 1) {
        if (self->obj != 0 && self->fe4 == 0) {
            self->fe4 = 1;
            FUN_00062160(self->obj, DAT_003da704);
        }
    } else if (DAT_003e48b8 == 2) {
    } else if (DAT_003e48b8 == 3) {
        FUN_0013a7a0(self);
    }
}
