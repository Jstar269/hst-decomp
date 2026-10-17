/* HSTMATCH module=EBOOT.BIN start=0x001c36d8 end=0x001c38c0 symbol=FUN_001c36d8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* When the counter at +8 is zero it calls 0x6391c, 0x1b3ea4 and 0x1b4848; once the counter reaches the limit at +0xfc it creates the 0x48-byte
   global object DAT_0034a81c (constructed through 0x2914c0) if missing and, when the byte poll 0x2911c0 returns zero, calls 0x2911cc, deletes
   the object (virtual deleting dtor), calls 0x6391c and 0x1cd88c. Matching idiom: `(f() != 0) ^ 1` for the negated byte-returning poll.
   Names provisional. */
struct Ctx {
    char pad[0xc];
    int f0c;
    char pad2[0x52 - 0x10];
    unsigned char b52;
};
struct Obj {
    virtual ~Obj();
};
struct Link {
    char pad[0xf0];
    unsigned char bf0;
};
struct Self {
    char pad[8];
    int f8;
    char pad2[0x18 - 0xc];
    Link *p18;
    char pad3[0xf8 - 0x1c];
    int f0f8;
    int f0fc;
    int f100;
    unsigned char b104;
};
extern Ctx *DAT_00331b84;
extern int DAT_0034a818;
extern Obj *DAT_0034a81c;
extern char DAT_0034179c;
extern "C" {
void FUN_0006391c(float, Ctx *, int);
void FUN_00063a30(float, Ctx *, int);
void FUN_001b3ea4(float, void *);
void FUN_001b4848(float, void *);
void FUN_001b2430(void *);
void *FUN_00000bcc(unsigned);
void FUN_002914c0(void *, int);
int FUN_0008d9ac(int);
void FUN_00291158(int, int, Obj *);
unsigned char FUN_002911c0(int);
void FUN_002911cc(int);
void FUN_001cd88c(Self *, int, int);
}

extern "C" void FUN_001c36d8(Self *self)
{
    if (self->f8 == 0) {
        FUN_0006391c(65535.0f, DAT_00331b84, self->f0fc);
        FUN_001b3ea4(0.5f, &DAT_0034179c);
        FUN_001b4848(0.5f, &DAT_0034179c);
    }
    if (self->f8 >= self->f0fc) {
        if (DAT_0034a81c == 0) {
            FUN_001b2430(&DAT_0034179c);
            void *p = FUN_00000bcc(0x48);
            if (p != 0)
                FUN_002914c0(p, 1);
            FUN_00291158(DAT_0034a818, FUN_0008d9ac(self->f0f8), DAT_0034a81c);
            FUN_00063a30(65535.0f, DAT_00331b84, 1);
            if (DAT_0034a81c == 0) {
                FUN_001cd88c(self, self->f100, 1);
                return;
            }
            if (self->b104 != 0) {
                Ctx *g = DAT_00331b84;
                g->f0c = 0;
                g->b52 = 0;
            }
        }
        if (DAT_0034a81c != 0 && ((FUN_002911c0(DAT_0034a818) != 0) ^ 1)) {
            FUN_002911cc(DAT_0034a818);
            if (DAT_0034a81c != 0) {
                delete DAT_0034a81c;
                DAT_0034a81c = 0;
            }
            FUN_0006391c(65534.0f, DAT_00331b84, 0);
            FUN_001cd88c(self, self->f100, 1);
            if (self->b104 != 0)
                self->p18->bf0 = 1;
        }
    }
}
