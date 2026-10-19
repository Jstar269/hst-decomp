/* HSTMATCH module=EBOOT.BIN start=0x0022bfcc end=0x0022c02c symbol=FUN_0022bfcc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { int x[32]; } Buf;
extern void *DAT_003415a8;
extern int FUN_001bfbe8(void *buf, int v);
extern int FUN_001c02e0(void *buf, int idx, int v);

int FUN_0022bfcc(int idx, int v, Buf *buf)
{
    int val = v;

    if (buf == 0)
        buf = (Buf *)((char *)DAT_003415a8 + 0x80);
    if (idx == 16)
        return FUN_001bfbe8(buf, val);
    return (unsigned)(((unsigned char)FUN_001c02e0(buf, idx, val)) - 4) < 2;
}
