/* HSTMATCH module=hstp_trans_main.prx start=0x00249a24 end=0x00249c14 symbol=FUN_00249a24 lang=c++ */
/* Clone of src/eboot/input_flag_query_0023988c.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Collects input/runtime flags into eight byte outputs: four one-bit reads through FUN_0001e6b0 over the register block at +0x17a4..+0x17b0, then four 2-bit status fields of the config byte at DAT_003751d4+0x89, each reported inverted. The outputs are cleared with a chained assignment, which is why the stores appear in reverse order. */
typedef unsigned char u8;

struct Cfg {
    u8 pad[0x89];
    signed char f0 : 2;
    signed char f1 : 2;
    signed char f2 : 2;
    signed char f3 : 2;
};

extern Cfg *DAT_003751d4;

extern "C" unsigned FUN_0001e6b0(Cfg *cfg, void *p, int a, int b, int c);

extern "C" void FUN_00249a24(u8 *obj, u8 *o1, u8 *o2, u8 *o3, u8 *o4, u8 *o5, u8 *o6,
                             u8 *o7, u8 *o8) {
    *o1 = *o2 = *o3 = *o4 = 0;
    *o1 |= (unsigned char)FUN_0001e6b0(DAT_003751d4, obj + 0x17a4, 0x80, 2, 9);
    *o2 |= (unsigned char)FUN_0001e6b0(DAT_003751d4, obj + 0x17a8, 0x20, 2, 9);
    *o3 |= (unsigned char)FUN_0001e6b0(DAT_003751d4, obj + 0x17ac, 0x10, 2, 9);
    *o4 |= (unsigned char)FUN_0001e6b0(DAT_003751d4, obj + 0x17b0, 0x40, 2, 9);
    *o5 = *o6 = *o7 = *o8 = 0;
    *o5 |= DAT_003751d4->f3 == 0;
    *o6 |= DAT_003751d4->f1 == 0;
    *o7 |= DAT_003751d4->f0 == 0;
    *o8 |= DAT_003751d4->f2 == 0;
}
