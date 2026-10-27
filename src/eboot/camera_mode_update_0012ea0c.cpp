/* HSTMATCH module=EBOOT.BIN start=0x0012ea0c end=0x0012edf0 symbol=FUN_0012ea0c lang=c++ */
/* Clone of src/sharing_main/camera_mode_update_00139f64.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Camera mode update (mode global DAT_0033b578): mode 0 nudges the float at +0xe8 by two 2-bit pad fields, resets
   the camera globals (DAT_002dadd0 is the value build_basis copies into the basis' angle slot) and clamps +0xe8;
   modes 3/4 clamp the globals into their [lo, hi] pairs. Matching idioms: the "neither field pressed" test is the
   inline THEN arm (inverted condition), the bounds go through a const& Clamp (retail reloads them), and retail's
   dead `else if (mode == 3)` arm after the 3/4 test is kept. */
struct Pad {                /* DAT_002cfc8c */
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

extern Pad *DAT_002cfc8c;
extern int DAT_003313c4;
extern int DAT_0033b578;
extern float DAT_0033b57c;
extern float DAT_002dadd0;
extern float DAT_002daddc;
extern float DAT_002dade0;
extern float DAT_002dade8;
extern float DAT_002dadf0;
extern float DAT_002dadf4;
extern float DAT_002dadf8;
extern float DAT_002dadfc;
extern float DAT_002dae00;
extern float DAT_002dae04;
extern float DAT_002dae08;
extern float DAT_002dae0c;

extern "C" void FUN_000612dc(CamObj *, int);
extern "C" void FUN_0012f248(Obj *);

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" void FUN_0012ea0c(Obj *self)
{
    if (DAT_0033b578 == 0) {
        if (DAT_002cfc8c->a1 != 1 && DAT_002cfc8c->a0 != 1) {
            self->fec = 0;
        } else {
            if (DAT_002cfc8c->a1 == 1 && DAT_002cfc8c->a0 == 1) {
                self->fe8 += -self->fe8 * 0.3f;
                self->fec = 1;
            } else if (DAT_002cfc8c->a1 == 1 && self->fec == 0) {
                self->fe8 -= 2.0f;
            } else if (DAT_002cfc8c->a0 == 1 && self->fec == 0) {
                self->fe8 += 2.0f;
            }
        }
        DAT_002dadd0 = 40.0f;
        DAT_002daddc = 19.8f;
        DAT_002dade0 = 35.0f;
        DAT_0033b57c = 0.0f;
        DAT_002dade8 = 20.0f;
        self->fe8 = Clamp(self->fe8, -DAT_002dade8, DAT_002dade8);
        FUN_0012f248(self);
    } else if (DAT_0033b578 == 3 || DAT_0033b578 == 4) {
        DAT_002dadd0 = Clamp(DAT_002dadd0, DAT_002dadf0, DAT_002dadf4);
        DAT_002daddc = Clamp(DAT_002daddc, DAT_002dadf8, DAT_002dadfc);
        DAT_002dade0 = Clamp(DAT_002dade0, DAT_002dae00, DAT_002dae04);
        DAT_0033b57c = Clamp(DAT_0033b57c, DAT_002dae08, DAT_002dae0c);
        self->fe8 = Clamp(self->fe8, -DAT_002dade8, DAT_002dade8);
        FUN_0012f248(self);
    } else if (DAT_0033b578 == 1) {
        if (self->obj != 0 && self->fe4 == 0) {
            self->fe4 = 1;
            FUN_000612dc(self->obj, DAT_003313c4);
        }
    } else if (DAT_0033b578 == 2) {
    } else if (DAT_0033b578 == 3) {
        FUN_0012f248(self);
    }
}
