/* HSTMATCH module=EBOOT.BIN start=0x0006dc58 end=0x0006ddb4 symbol=FUN_0006dc58 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* a0 = the object (current buffer index at +84, a pointer table at +100), a1 = the element index (stride 28),
   a2 = four floats. Each component is converted with a float -> unsigned int cast and stored as a byte; the
   fourth component is pre-scaled by 255/128. The table pointer and the index are reloaded for every byte
   because the stores may alias. Matching idiom: the `(unsigned int)x` cast gives retail's 2^31 threshold block
   (c.le.s / bc1t); a hand-written threshold test only reaches c.ngt.s. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Obj {
    u8 pad0[84];
    u32 cur;                     /* 84: current buffer index */
    u8 pad58[12];                /* 88..99 */
    u32 tbl[1];                  /* 100: buffer pointer table */
} Obj;

void FUN_0006dc58(Obj *a0, int idx, float *v)
{
    int off = idx * 28;

    *(u8 *)(a0->tbl[a0->cur] + off) = (u8)(u32)v[0];
    *(u8 *)(off + a0->tbl[a0->cur] + 1) = (u8)(u32)v[1];
    *(u8 *)(off + a0->tbl[a0->cur] + 2) = (u8)(u32)v[2];
    *(u8 *)(off + a0->tbl[a0->cur] + 3) = (u8)(u32)(v[3] * 1.9921875f);
}
