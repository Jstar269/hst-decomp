/* HSTMATCH module=hstp_trans_main.prx start=0x00272a4c end=0x00272b98 symbol=FUN_00272a4c lang=c++ */
/* Clone of src/eboot/record_color_scale_00261c24.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Index into a table of 0xf0-byte records: resets three sub-object colours to 0x80606060, then scales the packed RGB at +0x18 by 0.75 and re-packs it with the 0x80000000 tag. */

extern "C" void FUN_001055a4(void *p, unsigned arg);

struct Rec_261c24 {
    void *f0;
    void *f4;
    void *f8;
    void *f_c;
    void *f10;
    void *f14;
    unsigned f18;
};

extern "C" void FUN_00272a4c(char *base, int i)
{
    Rec_261c24 *r = (Rec_261c24 *)(base + i * 0xf0);
    FUN_001055a4(r->f0, 0x80606060);
    FUN_001055a4(r->f_c, 0x80606060);
    FUN_001055a4(r->f14, 0x80606060);
    unsigned c = r->f18;
    int rr = (int)((float)((c >> 16) & 0xff) * 0.75f) & 0xff;
    int gg = (int)((float)((c >> 8) & 0xff) * 0.75f) & 0xff;
    int bb = (int)((float)(c & 0xff) * 0.75f) & 0xff;
    FUN_001055a4(r->f10, 0x80000000 | (rr << 16) | (gg << 8) | bb);
}
