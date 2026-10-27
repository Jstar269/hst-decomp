/* HSTMATCH module=EBOOT.BIN start=0x000503d0 end=0x00050534 symbol=FUN_000503d0 lang=c++ */
/* Clone of src/sharing_main/ge_screen_transfer_00050cac.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Twin of EBOOT 0x503d0. Records a GE block transfer of a 480x272 image into a display list: a 24-byte descriptor
   (first field f, rest zero-initialised: the bytewise zeroing loop) selects the list state through FUN_0003cc80 /
   FUN_0003ca68, FUN_0003cc48(ctx, 0.0f) returns the command pointer, then TEXSYNC (0xcc), TRANSFERSIZE (0xee,
   479x271), TRANSFERSRCPOS (0xeb), TRANSFERSRCW/SRC (0xb3/0xb2: buffer DAT_0032b248, stride 512), TRANSFERDSTPOS
   (0xec), TRANSFERDSTW/DST (0xb5/0xb4: the screen buffer object at +0x1a0a4, stride 480), TRANSFERSTART (0xea,
   32-bit pixels unless the mode byte at +0x1a0a0 is set; C++ bool conversion of `!mode` gives the andi), TEXFLUSH,
   TEXSYNC, and closes the list with FUN_0003cae8. Names provisional. */
struct Desc {
    float f;
    int a;
    int b;
    int c;
    int d;
    int e;
};

struct Obj;

struct Self {
    char pad00[0x1a00c];
    void *ctx;
    char pad1a010[0x1a0a0 - 0x1a010];
    unsigned char mode;
    Obj *obj;
};

extern "C" {
extern unsigned DAT_0032b248;
extern void *DAT_0032b17c;
void *FUN_0003cc80(void *, Desc *);
int FUN_0003ca68(void *, void *);
unsigned *FUN_0003cc48(void *, float);
unsigned FUN_00051450(Obj *);
void FUN_0003cae8(void *, unsigned *);
}

extern "C" void FUN_000503d0(Self *self, float f)
{
    unsigned *p;
    unsigned src;
    unsigned dst;
    Desc d = {f};

    FUN_0003ca68(self->ctx, FUN_0003cc80(self->ctx, &d));
    p = FUN_0003cc48(self->ctx, 0.0f);
    src = DAT_0032b248;
    dst = FUN_00051450(self->obj);
    p[0] = 0xcc000000;
    p[1] = 0xee043ddf;
    p[2] = 0xeb000000;
    p[3] = ((src >> 24) & 0xff) << 16 | 0xb3000200;
    p[4] = (src & 0xffffff) | 0xb2000000;
    p[5] = 0xec000000;
    p[6] = ((dst >> 24) & 0xff) << 16 | 0xb50001e0;
    p[7] = (dst & 0xffffff) | 0xb4000000;
    p[8] = !self->mode | 0xea000000;
    p[9] = 0xcb000000;
    p[10] = 0xcc000000;
    FUN_0003cae8(DAT_0032b17c, p + 11);
}
