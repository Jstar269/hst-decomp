/* HSTMATCH module=EBOOT.BIN start=0x0008cb68 end=0x0008cd9c symbol=FUN_0008cb68 lang=c++ */
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
Sub9e0 *FUN_0008be64(void *);
extern char DAT_003071f4;
extern char DAT_002d26b4[];
extern unsigned char DAT_002d2442;
extern unsigned char DAT_003386b8;
extern Obj *DAT_003386c8;
extern unsigned char DAT_003417be;
extern int DAT_0034a678;
extern int DAT_0034a67c;
extern char DAT_0030fe20;
void FUN_0001f06c(void *);
void FUN_00000010(void *);
void FUN_002b7960(int, int);
void FUN_002a4938(void);
void FUN_0008d72c(void *, int);
void FUN_0008d6cc(void *, int);
void FUN_00000788(void *, void *, int, int);
void FUN_000007f4(void *, void *, void *, int, int);
void FUN_00000a00(void *);
void *FUN_00000bcc(unsigned);
void FUN_0008d47c(void *);
void FUN_0008cea4(void *);
void FUN_000114c0(void *, int, int);
void FUN_0008cd9c(void *);
void FUN_0001f21c(void *, void *);
void FUN_00000018(void);
}

inline Big::Big()
{
    FUN_0008d47c(this);
    FUN_0008cea4((char *)this + 0x4e8);
    FUN_000007f4((char *)this + 0x940, (void *)FUN_0008cea4, (void *)FUN_0008d72c, 0x458, 4);
    FUN_000007f4((char *)this + 0x1aa0, (void *)FUN_0008cea4, (void *)FUN_0008d72c, 0x458, 4);
    FUN_0008cea4((char *)this + 0x2c20);
    FUN_0008cea4((char *)this + 0x3078);
    FUN_000114c0(this, 0, 0x38e0);
    FUN_0008cd9c(this);
}

inline Big::~Big()
{
    FUN_0008d72c((char *)this + 0x3078, -1);
    FUN_0008d72c((char *)this + 0x2c20, -1);
    FUN_00000788((char *)this + 0x1aa0, (void *)FUN_0008d72c, 0x458, 4);
    FUN_00000788((char *)this + 0x940, (void *)FUN_0008d72c, 0x458, 4);
    FUN_0008d72c((char *)this + 0x4e8, -1);
    FUN_0008d6cc(this, -1);
}

extern "C" Obj *FUN_0008cb68(Obj *self)
{
    FUN_0001f06c(self);
    self->vptr = (int)&DAT_003071f4;
    self->f3c = 0;
    self->f40 = 0;
    self->f44 = 0;
    FUN_00000010(DAT_002d26b4);
    FUN_002b7960(0, 40);
    switch (DAT_0034a67c) {
    case 0x20:
    case 2:
        switch (DAT_0034a678) {
        case 0x24:
        case 0x25:
        case 0x26:
            break;
        default:
            FUN_002a4938();
            break;
        }
        break;
    default:
        FUN_002a4938();
        break;
    }
    DAT_003386c8 = self;
    DAT_002d2442 = 1;
    DAT_003386b8 = 0;
    DAT_003417be = 0;
    Big *m = self->f40;
    if (m != 0) {
        delete m;
        self->f40 = 0;
    }
    self->f40 = new Big;
    Sub9e0 *o = (Sub9e0 *)operator new(0x9e0);
    if (o != 0)
        o = FUN_0008be64(o);
    self->f3c = o;
    FUN_0001f21c(&DAT_0030fe20, self);
    FUN_00000018();
    return self;
}

// matching idiom: the two nested type tests are `switch` statements (cases written in reverse of the tested order, retail's `beq` chain with a `b` to the default call);
// Big is `new Big` / `delete` with inline ctor/dtor bodies, Sub9e0 is `operator new` plus the out-of-line constructor call (`if (o) o = ctor(o)`).
