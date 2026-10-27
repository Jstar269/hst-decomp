/* HSTMATCH module=EBOOT.BIN start=0x00131198 end=0x001317bc symbol=FUN_00131198 rodata=0x002c1584 bss=0x00340288 lang=c++ */
/* Clone of src/sharing_main/cam_mode_position_0013c750.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Position for a camera mode (switch over kind, jump table at rodata=0x2c1584; mode 15 reads the "gimmick_cam01"
   node matrix); modes 1/2 keep the last position in a function-local static (bss=0x340288: guard byte, then the
   Vec4). The by-value GetPos() getters give retail's batched copies, member/pointer copies are memberwise pairs. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct Mat4 { Vec4 r0, r1, r2, r3; };

struct Pos { char pad[0x10]; Vec4 pos; Vec4 GetPos() const { return pos; } };
struct Info { char pad[0x58]; int f58; };
struct Game { char pad[0x88]; Pos *f88; char pad8c[0x9c - 0x8c]; Info *f9c; };
struct Cam { char pad[0x3c0]; Vec4 pos; Vec4 GetPos() const { return pos; } };
struct Player { char pad[0x5bc]; void *f5bc; };

struct Obj {
    char pad0[0x8c];
    int f8c;                 /* 0x8c */
    char pad90[0xc0 - 0x90];
    Vec4 fc0;                /* 0xc0 */
    char padd0[0xe0 - 0xd0];
    Vec4 fe0;                /* 0xe0 */
    char padf0[0xf3 - 0xf0];
    unsigned char ff3;       /* 0xf3 */
    char padf4[0xf8 - 0xf4];
    void *ff8;               /* 0xf8 */
    void *ffc;               /* 0xfc */
    char pad100[0x110 - 0x100];
    Vec4 f110;               /* 0x110 */
};

extern Game *DAT_003386b0;
extern Cam *DAT_003402a0;
extern float DAT_002db1a8;
extern char DAT_002db1ac[];
extern const Vec4 DAT_002bc440;

extern "C" {
int FUN_00131a78(Obj *o, int k);
Player *FUN_001317bc(Obj *o, int kind);
Vec4 *FUN_00093838(void *p);
void FUN_0005548c(Mat4 *out, void *node, const char *name);
void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00131198(Vec4 *out, Obj *o, int kind, int arg);
}

static inline bool operator==(const Vec4 &a, const Vec4 &b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

extern "C" void FUN_00131198(Vec4 *out, Obj *o, int kind, int arg)
{
    Vec4 r(0.0f, 0.0f, 0.0f, 1.0f);
    bool ok = true;
    if (o->f8c != 2 && DAT_003386b0->f9c->f58 > FUN_00131a78(o, 5))
        ok = false;
    switch (kind) {
    case 1:
    case 2: {
        static Vec4 s_last(0.0f, 0.0f, 0.0f, 1.0f);
        if (ok) {
            r = DAT_003386b0->f88->GetPos();
            r.y *= DAT_002db1a8;
            s_last = r;
        } else {
            r = s_last;
        }
        if (kind == 2)
            r.y = 0.0f;
        break;
    }
    case 5: case 6: case 7: case 8: case 9:
        r = *FUN_00093838(FUN_001317bc(o, kind)->f5bc);
        break;
    case 10:
        r = Vec4(2.65f, -1.2f, 0.0f, 1.0f);
        break;
    case 11:
        if (o->fe0.z > 0.0f) {
            if (o->fe0.x > 0.0f) r = Vec4(-5.3f, 0.0f, 11.0f, 1.0f);
            else r = Vec4(5.3f, 0.0f, 11.0f, 1.0f);
        } else {
            if (o->fe0.x > 0.0f) r = Vec4(-5.3f, 0.0f, -11.0f, 1.0f);
            else r = Vec4(5.3f, 0.0f, -11.0f, 1.0f);
        }
        break;
    case 12:
        if (o->fe0.z > 0.0f) r = Vec4(0.0f, 0.0f, 11.0f, 1.0f);
        else r = Vec4(0.0f, 0.0f, -11.0f, 1.0f);
        break;
    case 3:
        r = o->fc0;
        break;
    case 4:
        r = o->fe0;
        break;
    case 13:
        if (arg != -1 && arg != 13) {
            Vec4 t1;
            FUN_00131198(&t1, o, arg, -1);
            r = t1;
            Vec4 t2;
            FUN_00131198(&t2, o, arg == 6 ? 6 : 5, -1);
            if (t2.z > 0.0f) {
                Vec4 d(0.0f, 0.0f, -1.0f, 0.0f);
                FUN_00022418(&r, &r, &d);
            } else {
                Vec4 d(0.0f, 0.0f, 1.0f, 0.0f);
                FUN_00022418(&r, &r, &d);
            }
        } else {
            r = Vec4(0.0f, 0.0f, 0.0f, 1.0f);
        }
        break;
    case 14:
        r = DAT_003402a0->GetPos();
        break;
    case 15:
        if (o->ff8) {
            Mat4 m;
            FUN_0005548c(&m, o->ff8, DAT_002db1ac);
            r = m.r3;
            if (o->ffc && o->ff3) {
                Mat4 m2;
                FUN_0005548c(&m2, o->ffc, DAT_002db1ac);
                r = m2.r3;
            }
            if (r == DAT_002bc440)
                r = o->f110;
        } else {
            r = o->f110;
        }
        break;
    case 0:
    default:
        r = Vec4(0.0f, 0.0f, 0.0f, 1.0f);
        break;
    }
    *out = r;
}
