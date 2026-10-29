/* HSTMATCH module=hstp_trans_main.prx start=0x0008e2b0 end=0x0008e4e4 symbol=FUN_0008e2b0 lang=c++ */
/* Clone of src/eboot/scene_mgr_ctor_0008cb68.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (starting from the Ghidra draft, lane fm9); exact match verified; names and types await human review. */
struct Sub9e0 {
    char pad[0x9e0];
};

struct Big {
    char pad[0x38e0];
    Big();
    ~Big();
};

struct Obj {
    int vptr;
    char pad04[0x38];
    Sub9e0 *f3c;
    Big *f40;
    unsigned char f44;
};

void *operator new(unsigned int);
extern "C" {
Sub9e0 *FUN_0008d554(void *);
extern char DAT_003b04c0;
extern char DAT_003787ac[];
extern unsigned char DAT_003784fe;
extern unsigned char DAT_003e19f8;
extern Obj *DAT_003e1a08;
extern unsigned char DAT_003eaaf6;
extern int DAT_003f39a8;
extern int DAT_003f39ac;
extern char DAT_003b9120;
void FUN_0001ec44(void *);
void FUN_00000010(void *);
void FUN_002c7700(int, int);
void FUN_002b40c8(void);
void FUN_0008eec4(void *, int);
void FUN_0008ee64(void *, int);
void FUN_00000788(void *, void *, int, int);
void FUN_000007f4(void *, void *, void *, int, int);
void FUN_00000a00(void *);
void *FUN_00000bcc(unsigned);
void FUN_0008ebd0(void *);
void FUN_0008e5ec(void *);
void FUN_000114c0(void *, int, int);
void FUN_0008e4e4(void *);
void FUN_0001ef34(void *, void *);
void FUN_00000018(void);
}

inline Big::Big()
{
    FUN_0008ebd0(this);
    FUN_0008e5ec((char *)this + 0x4e8);
    FUN_000007f4((char *)this + 0x940, (void *)FUN_0008e5ec, (void *)FUN_0008eec4, 0x458, 4);
    FUN_000007f4((char *)this + 0x1aa0, (void *)FUN_0008e5ec, (void *)FUN_0008eec4, 0x458, 4);
    FUN_0008e5ec((char *)this + 0x2c20);
    FUN_0008e5ec((char *)this + 0x3078);
    FUN_000114c0(this, 0, 0x38e0);
    FUN_0008e4e4(this);
}

inline Big::~Big()
{
    FUN_0008eec4((char *)this + 0x3078, -1);
    FUN_0008eec4((char *)this + 0x2c20, -1);
    FUN_00000788((char *)this + 0x1aa0, (void *)FUN_0008eec4, 0x458, 4);
    FUN_00000788((char *)this + 0x940, (void *)FUN_0008eec4, 0x458, 4);
    FUN_0008eec4((char *)this + 0x4e8, -1);
    FUN_0008ee64(this, -1);
}

extern "C" Obj *FUN_0008e2b0(Obj *self)
{
    FUN_0001ec44(self);
    self->vptr = (int)&DAT_003b04c0;
    self->f3c = 0;
    self->f40 = 0;
    self->f44 = 0;
    FUN_00000010(DAT_003787ac);
    FUN_002c7700(0, 40);
    switch (DAT_003f39ac) {
    case 0x20:
    case 2:
        switch (DAT_003f39a8) {
        case 0x24:
        case 0x25:
        case 0x26:
            break;
        default:
            FUN_002b40c8();
            break;
        }
        break;
    default:
        FUN_002b40c8();
        break;
    }
    DAT_003e1a08 = self;
    DAT_003784fe = 1;
    DAT_003e19f8 = 0;
    DAT_003eaaf6 = 0;
    Big *m = self->f40;
    if (m != 0) {
        delete m;
        self->f40 = 0;
    }
    self->f40 = new Big;
    Sub9e0 *o = (Sub9e0 *)operator new(0x9e0);
    if (o != 0)
        o = FUN_0008d554(o);
    self->f3c = o;
    FUN_0001ef34(&DAT_003b9120, self);
    FUN_00000018();
    return self;
}

// matching idiom: the two nested type tests are `switch` statements (cases written in reverse of the tested order, retail's `beq` chain with a `b` to the default call);
// Big is `new Big` / `delete` with inline ctor/dtor bodies, Sub9e0 is `operator new` plus the out-of-line constructor call (`if (o) o = ctor(o)`).
