/* HSTMATCH module=hstp_trans_main.prx start=0x0023ba3c end=0x0023ba9c symbol=FUN_0023ba3c lang=c99 */
/* Clone of src/eboot/buf_select_0022bfcc.c (hstclone.py tag ds1018ar4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { int x[32]; } Buf;
extern void *DAT_003ea8e8;
extern int FUN_001cdb3c(void *buf, int v);
extern int FUN_001ce4f4(void *buf, int idx, int v);

int FUN_0023ba3c(int idx, int v, Buf *buf)
{
    int val = v;

    if (buf == 0)
        buf = (Buf *)((char *)DAT_003ea8e8 + 0x80);
    if (idx == 16)
        return FUN_001cdb3c(buf, val);
    return (unsigned)(((unsigned char)FUN_001ce4f4(buf, idx, val)) - 4) < 2;
}
