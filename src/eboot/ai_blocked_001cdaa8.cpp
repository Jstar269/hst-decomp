/* HSTMATCH module=EBOOT.BIN start=0x001cdaa8 end=0x001cdc9c symbol=FUN_001cdaa8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

/* Game object with a virtual position getter (slot 6). */
class Unit {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual const Vec4 *GetPos();
};

struct WorldBase { char pad[0xe0]; };
struct World : WorldBase, Unit {};

/* Viewer: a facing direction, an eye position and a view angle limit. */
struct Viewer {
    char pad0[0x20];
    Vec4 facing;        /* 0x20 */
    Vec4 eye;           /* 0x30 */
    float view_angle;   /* 0x40 */
};

extern World *DAT_0034a118;
extern float DAT_002ea2d4; /* lower bound of the cosine */
extern float DAT_002ea2d8; /* upper bound of the cosine */

extern "C" {
int FUN_001cde28(Unit *);
int FUN_001cddb0(Viewer *, Unit *);
void FUN_000542e8(Vec4 *, const Vec4 *, Vec4 *);
void FUN_000c3f38(Vec4 *, Vec4 *);
float FUN_001cdda8(Vec4 *, Vec4 *);
float FUN_001cdd68(float *, float *, float *);
float FUN_0000c5bc(float);
int FUN_001cdd14(Unit *);
int FUN_001cdcb0(Unit *);
Unit *FUN_001cdd0c(Unit *);
Unit *FUN_001cdca8(Unit *);
int FUN_001cdcdc(Unit *, int);
int FUN_00127870(int);
int FUN_00127a20(int);
Vec4 *FUN_00093818(Unit *);
Vec4 *FUN_001cdc9c(Unit *);

/* True when the unit pointed to is NOT in the viewer's sight (outside the view angle or behind a blocker). */
bool FUN_001cdaa8(Viewer *self, Unit **pp)
{
    bool visible;
    Unit *target = *pp;
    if (FUN_001cde28(target) != 0 && FUN_001cddb0(self, target) != 0) {
        Unit *world = DAT_0034a118;
        if (target != world) {
            Vec4 dir;
            Vec4 to_target;
            FUN_000542e8(&to_target, target->GetPos(), &self->eye);
            FUN_000c3f38(&dir, &to_target);
            float d = FUN_001cdda8(&self->facing, &dir);
            float angle = FUN_0000c5bc(FUN_001cdd68(&d, &DAT_002ea2d4, &DAT_002ea2d8));
            if (angle < self->view_angle) {
                if (FUN_001cdd14(target) != 0) {
                    Unit *other = FUN_001cdd0c(target);
                    if (FUN_00127870(FUN_001cdcdc(other, 0)) == 0 && FUN_00127a20(FUN_001cdcdc(other, 0)) == 0) {
                        d = FUN_001cdda8(FUN_00093818(other) + 2, &self->facing);
                        if (d >= 0.0f) {
                            visible = false;
                            goto end;
                        }
                    }
                } else if (FUN_001cdcb0(target) != 0) {
                    Unit *other = FUN_001cdca8(target);
                    d = FUN_001cdda8(FUN_001cdc9c(other) + 2, &self->facing);
                    if (d >= 0.0f) {
                        visible = false;
                        goto end;
                    }
                    d = FUN_001cdda8(FUN_001cdc9c(other) + 2, &dir);
                    if (d >= 0.0f) {
                        visible = false;
                        goto end;
                    }
                }
                visible = true;
                goto end;
            }
        }
    }
    visible = false;
end:
    return !visible;
}
}
