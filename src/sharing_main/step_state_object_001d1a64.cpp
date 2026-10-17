/* HSTMATCH module=hstp_trans_main.prx start=0x001d1a64 end=0x001d1c4c symbol=FUN_001d1a64 lang=c++ */
/* Clone of src/eboot/step_state_object_001c36d8.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* When the counter at +8 is zero it calls 0x6391c, 0x1b3ea4 and 0x1b4848; once the counter reaches the limit at +0xfc it creates the 0x48-byte
   global object DAT_003f3b4c (constructed through 0x2914c0) if missing and, when the byte poll 0x2911c0 returns zero, calls 0x2911cc, deletes
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
extern Ctx *DAT_003daec4;
extern int DAT_003f3b48;
extern Obj *DAT_003f3b4c;
extern char DAT_003eaad8;
extern "C" {
void FUN_000647e0(float, Ctx *, int);
void FUN_000648f4(float, Ctx *, int);
void FUN_001c2130(float, void *);
void FUN_001c28a4(float, void *);
void FUN_001c04c4(void *);
void *FUN_00000bcc(unsigned);
void FUN_002a2acc(void *, int);
int FUN_0008f188(int);
void FUN_002a2860(int, int, Obj *);
unsigned char FUN_002a28c8(int);
void FUN_002a28d4(int);
void FUN_001dbf68(Self *, int, int);
}

extern "C" void FUN_001d1a64(Self *self)
{
    if (self->f8 == 0) {
        FUN_000647e0(65535.0f, DAT_003daec4, self->f0fc);
        FUN_001c2130(0.5f, &DAT_003eaad8);
        FUN_001c28a4(0.5f, &DAT_003eaad8);
    }
    if (self->f8 >= self->f0fc) {
        if (DAT_003f3b4c == 0) {
            FUN_001c04c4(&DAT_003eaad8);
            void *p = FUN_00000bcc(0x48);
            if (p != 0)
                FUN_002a2acc(p, 1);
            FUN_002a2860(DAT_003f3b48, FUN_0008f188(self->f0f8), DAT_003f3b4c);
            FUN_000648f4(65535.0f, DAT_003daec4, 1);
            if (DAT_003f3b4c == 0) {
                FUN_001dbf68(self, self->f100, 1);
                return;
            }
            if (self->b104 != 0) {
                Ctx *g = DAT_003daec4;
                g->f0c = 0;
                g->b52 = 0;
            }
        }
        if (DAT_003f3b4c != 0 && ((FUN_002a28c8(DAT_003f3b48) != 0) ^ 1)) {
            FUN_002a28d4(DAT_003f3b48);
            if (DAT_003f3b4c != 0) {
                delete DAT_003f3b4c;
                DAT_003f3b4c = 0;
            }
            FUN_000647e0(65534.0f, DAT_003daec4, 0);
            FUN_001dbf68(self, self->f100, 1);
            if (self->b104 != 0)
                self->p18->bf0 = 1;
        }
    }
}
