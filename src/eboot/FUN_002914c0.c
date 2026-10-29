/* HSTMATCH module=EBOOT.BIN start=0x002914c0 end=0x00291688 symbol=FUN_002914c0 lang=c99 data=0x002ff9a8 */
/* Hand-written reconstruction from the disassembly (Ghidra pseudocode shape); matching idiom: the inner object is allocated in the condition (if ((o = alloc(0x1f0)) != 0)) so the copy lands in the beqz slot and the holder store after the join is not merged into a likely branch; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ff9a8-0x002ff9bb) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/player_service.h"

extern char DAT_00309db4;
extern char DAT_00309dc0;
extern void *DAT_0034a81c;
extern ServiceHolder *DAT_0034a818;
extern PlayerService *DAT_0034a808;
extern void *FUN_00000bcc(unsigned);
extern void *FUN_000114c0(void *, int, unsigned);
extern void FUN_00050fc0(void *);
extern void FUN_0028f5e4(PlayerService *, int);
extern int FUN_0004e780(int *, int *, int, int, int, int);
extern void FUN_00051274(void *, const char *, int, int, int);
extern int FUN_00051450(void *);
extern void FUN_00022d7c(int, int, int);
extern void FUN_00051398(float, void *);

/* The 512x272 (screen-sized) texture the material is created with. */
enum { TEXTURE_WIDTH = 0x200, TEXTURE_HEIGHT = 0x110 };

struct Player {
    unsigned int vtable;
    char pad[0x1c];
    unsigned char unk20;
    unsigned char unk21;
    unsigned char unk22;
};

/* Constructor: builds the global holder and its PlayerService, then registers the PsmfPlayerMaterial resource. */
struct Player *FUN_002914c0(struct Player *self, int init_arg)
{
    ServiceHolder *h;
    int out_a;
    int out_b;

    FUN_00050fc0(self);
    self->vtable = (unsigned int)&DAT_00309db4;
    DAT_0034a81c = self;
    h = (ServiceHolder *)FUN_00000bcc(4);
    if (h != 0) {
        PlayerService *o;
        h->service = 0;
        if ((o = (PlayerService *)FUN_00000bcc(PLAYER_SERVICE_SIZE)) != 0) {
            o->ready = 0;
            o->unk29 = 0;
            o->unk2a = 0;
            o->unk2c = 0;
            o->unk30 = 0;
            o->a.vtable = (unsigned int)&DAT_00309dc0;
            o->a.handle = -1;
            o->b.vtable = (unsigned int)&DAT_00309dc0;
            o->b.handle = -1;
            o->c.vtable = (unsigned int)&DAT_00309dc0;
            o->c.handle = -1;
            o->unkdc = 0;
            o->unke0 = 0;
            o->unke4 = 0;
            o->unke8 = 0;
            DAT_0034a808 = o;
            /* zero the sub-blocks */
            FUN_000114c0(o, 0, 4);
            FUN_000114c0((char *)o + 4, 0, 12);
            FUN_000114c0((char *)o + 16, 0, 24);
            FUN_000114c0((char *)o + 212, 0, 8);
            FUN_000114c0(&o->req_cmd, 0, SERVICE_REQUEST_SIZE);
            FUN_000114c0((char *)o + 236, 0, 256);
        }
        h->service = o;
        DAT_0034a818 = h;
    }
    FUN_0028f5e4(DAT_0034a818->service, init_arg);
    out_a = 0;
    out_b = 0;
    FUN_00051274(self, "PsmfPlayerMaterial", FUN_0004e780(&out_a, &out_b, 3, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT), 1, 0x10);
    FUN_00022d7c(FUN_00051450(self), 0, 0x88000);
    FUN_00051398(9998.0f, self);
    self->unk21 = 0;
    self->unk22 = 0;
    return self;
}
