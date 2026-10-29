/* HSTMATCH module=EBOOT.BIN start=0x00126d48 end=0x00127004 symbol=FUN_00126d48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/avatar_obj.h"

/* Character record looked up by id; bytes 0x24..0x2b are copied into the avatar. */
struct Info {
    char pad0[0x24];
    unsigned char f24, f25, f26, f27, f28, f29, f2a, f2b;
};
struct AvatarElem { char pad[0x1b4]; int id; };
struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));

struct Node8 { char pad[8]; int f8; };
struct Holder { char pad[8]; Node8 *f8; };

/* Skeleton: bone positions by index (GetPos is virtual slot 5). */
struct AvatarSkel {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void GetPos(Vec4 *, int);
    char pad4[0x8c - 4];
    Holder *f8c;
};

/* Virtual slots of the avatar itself (the data layout is in avatar_obj.h). */
struct AvatarVirt {
    virtual void m0();
    virtual void Refresh();
};

extern int DAT_0033b4a8;
extern char DAT_002da7f0[];
extern char DAT_002da800[]; /* "Bip01LFoot" */

extern "C" {
void FUN_00194e20();
void FUN_00194e34(Avatar *, int);
void FUN_001277e8(Avatar *);
void FUN_0005ed18(AvatarElem *, int, int);
void FUN_0005f030(AvatarElem *, int, float);
Info *FUN_00193474(int);
Info *FUN_00193024(void *);
void FUN_000143b0(void *, void *);
void FUN_0019494c(Avatar *, void *, int, int, int, int);
int FUN_0002fe08(Node8 *);
void *FUN_0002fe18(Node8 *, int);
int FUN_00014934(void *, void *);
void FUN_00127004(Avatar *);
void FUN_0012a254(Avatar *, int, int, int);

/* Copy the record's flag bytes into the avatar. */
static inline void CopyInfo(Avatar *s, Info *i)
{
    s->unk354 = i->f24;
    s->unk35c = i->f2b;
    s->unk364 = i->f25;
    s->unk365 = i->f26;
    s->unk366 = i->f27;
    s->unk367 = i->f28;
    s->unk368 = i->f29;
    s->unk369 = i->f2a;
}

/* Number of bones of the skeleton. */
static inline int Count(Avatar *s)
{
    Node8 *n = s->skel->f8c->f8;
    return n ? FUN_0002fe08(n) : 0;
}

/* Name of bone i. */
static inline void *NameAt(Avatar *s, int i)
{
    Node8 *n = s->skel->f8c->f8;
    return n ? FUN_0002fe18(n, i) : 0;
}

/* Set the avatar up for `mode` (0, 1 or other), load its record, find the left-foot bone and refresh. */
void FUN_00126d48(Avatar *self, int mode, int arg)
{
    char name[32];
    Vec4 pos;
    self->unk254 = mode == 0;
    if (mode == 0) {
        FUN_00194e20();
        FUN_0005ed18(self->elem, 0, self->unk70);
        FUN_0005f030(self->elem, 0, 0.0f);
        Info *info = FUN_00193474(self->elem->id);
        if (info != 0) {
            CopyInfo(self, info);
        }
    } else if (mode == 1) {
        FUN_000143b0(name, DAT_002da7f0);
        FUN_0019494c(self, name, DAT_0033b4a8, 800, 0, 0);
        FUN_0005ed18(self->elem, 0, self->unk70);
        FUN_0005f030(self->elem, 0, 0.0f);
        Info *info = FUN_00193024(name);
        if (info != 0) {
            CopyInfo(self, info);
        }
    } else {
        FUN_00194e34(self, arg);
        FUN_001277e8(self);
        FUN_0005ed18(self->elem, 0, self->unk70);
        FUN_0005f030(self->elem, 0, 0.0f);
        Info *info = FUN_00193474(self->elem->id);
        if (info != 0) {
            CopyInfo(self, info);
        }
    }
    for (int i = 0; i < Count(self); i++) {
        if (FUN_00014934(NameAt(self, i), DAT_002da800) == 0) {
            self->skel->GetPos(&pos, i);
            self->unk328 = (pos.z + (pos.x + pos.y)) / 3.0f;
        }
    }
    FUN_00127004(self);
    FUN_0012a254(self, 0, -1, 0);
    ((AvatarVirt *)self)->Refresh();
}
}
