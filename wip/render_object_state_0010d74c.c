/* HSTMATCH module=EBOOT.BIN start=0x0010d74c end=0x0010d93c symbol=FUN_0010d74c lang=c99 */

typedef unsigned char bool;
#define true 1
#define false 0

typedef struct Self Self;
typedef struct TargetA TargetA;
typedef struct TargetB TargetB;

struct Vec4 {
    float x, y, z, w;
};

struct TargetA {
    char pad[0x40];
    float f40;
    float f44;
    char pad48[0x50 - 0x48];
    unsigned short f50;
    char pad52[0x70 - 0x52];
    float f70;
    float f74;
};

struct TargetB {
    char pad[0x5e];
    short f5e;
    short f60;
    short f62;
    short f64;
};

struct Self {
    char pad[0x7c];
    float f7c;          // 0x7c (124)
    float f80;          // 0x80 (128)
    char pad84[0x94 - 0x84];
    float f94;          // 0x94 (148)
    char pad98[0xb0 - 0x98];
    float fb0;          // 0xb0 (176)
    float fb4;          // 0xb4 (180)
    char padb8[0xd0 - 0xb8];
    float fd0;          // 0xd0 (208)
    float fd4;          // 0xd4 (212)
    short fd8;          // 0xd8 (216)
    short pad_da;       // 0xda
    float fdc;          // 0xdc (220)
    float fe0;          // 0xe0 (224)
    float fe4;          // 0xe4 (228)
    float fe8;          // 0xe8 (232)
    char padec[0xf8 - 0xec];
    int ff8;            // 0xf8 (248)
    short f_fc;         // 0xfc (252)
    short f_fe;         // 0xfe (254)
    char pad100[4];
    short f104;         // 0x104 (260)
    short pad106;
    float f108;         // 0x108 (264)
    float f10c;         // 0x10c (268)
    float f110;         // 0x110 (272)
    float f114;         // 0x114 (276)
    char pad118[0x120 - 0x118];
    struct Vec4 color;  // 0x120 (288)
    short f130;         // 0x130 (304)
    short f132;         // 0x132 (306)
    short f134;         // 0x134 (308)
    short f136;         // 0x136 (310)
    int f138;           // 0x138 (312)
    float f13c;         // 0x13c (316)
    float f140;         // 0x140 (320)
    unsigned char f144; // 0x144 (324)
    unsigned char f145; // 0x145 (325)
    char pad146[2];
    float f148;         // 0x148 (328)
    char pad14c;
    unsigned char f14d; // 0x14d (333)
};

extern TargetB *DAT_00310fc4;
extern TargetA *DAT_0034176c;

void FUN_00102490(void);
void FUN_00042ff4(void *obj, float val);
void FUN_00197464(TargetA *obj, struct Vec4 *color);
void FUN_00197458(TargetA *obj, float x, float y);
void FUN_00198228(TargetA *obj, int id, bool flag);
void FUN_0010d74c(Self *self);

void FUN_0010d74c(Self *self)
{
    FUN_00102490();
    if (self->f144 != 0) return;
    if (self->f145 != 0) return;

    FUN_00042ff4(DAT_00310fc4, self->f148);

    float t1 = self->f80 * self->f108;
    float t2 = self->f94 * self->f10c;
    float t3 = self->f114 * t1;
    float t4 = self->f114 * t2;

    unsigned char inc = 1;
    if (self->f114 < 1.0f) {
        // inc = 1
    } else {
        inc = 0;
    }
    float fdc = self->f110 * t3;

    self->fd0 = self->fb0 + (float)self->f_fc * self->f80;
    self->fd4 = self->fb4 + (float)(short)(self->f_fe + inc) * self->f94;
    self->fd8 = self->f104;
    self->fdc = fdc;
    self->fe0 = t4;
    self->fe4 = self->f13c;
    self->fe8 = self->f140;

    if (self->ff8 != 0) {
        struct Vec4 color = self->color;
        color.w = color.w * self->f7c;

        FUN_00197464(DAT_0034176c, &color);

        TargetA *a = DAT_0034176c;
        a->f40 = self->fd0;
        a->f44 = self->fd4;
        a->f50 = (unsigned short)self->fd8;

        FUN_00197458(DAT_0034176c, self->fdc, self->fe0);

        a = DAT_0034176c;
        a->f70 = self->fe4;
        a->f74 = self->fe8;

        TargetB *b = DAT_00310fc4;
        b->f5e = self->f130;
        b->f60 = self->f132;
        b->f62 = self->f134;
        b->f64 = self->f136;

        bool flag = (self->f14d != 0);
        if (!flag) {
            flag = (self->f138 == 1);
        }
        FUN_00198228(DAT_0034176c, self->ff8, flag);
    }
}
// near miss from lane ag3 (unreviewed)
