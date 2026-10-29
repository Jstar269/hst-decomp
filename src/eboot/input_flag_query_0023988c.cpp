/* HSTMATCH module=EBOOT.BIN start=0x0023988c end=0x00239a7c symbol=FUN_0023988c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Collects input/runtime flags into eight byte outputs: four one-bit reads through FUN_0001ea64 over the register block at +0x17a4..+0x17b0, then four 2-bit status fields of the config byte at DAT_002cfc8c+0x89, each reported inverted. The outputs are cleared with a chained assignment, which is why the stores appear in reverse order. */
typedef unsigned char u8;

struct Cfg {
    u8 pad[0x89];
    signed char status0 : 2;   /* four 2-bit status fields of the byte at 0x89 */
    signed char status1 : 2;
    signed char status2 : 2;
    signed char status3 : 2;
};

extern Cfg *DAT_002cfc8c;

extern "C" unsigned FUN_0001ea64(Cfg *cfg, void *p, int a, int b, int c);

/* Fill the eight byte outputs: o1..o4 from the register block, o5..o8 from the config status fields. */
extern "C" void FUN_0023988c(u8 *regs, u8 *o1, u8 *o2, u8 *o3, u8 *o4, u8 *o5, u8 *o6,
                             u8 *o7, u8 *o8) {
    *o1 = *o2 = *o3 = *o4 = 0;
    *o1 |= (unsigned char)FUN_0001ea64(DAT_002cfc8c, regs + 0x17a4, 0x80, 2, 9);
    *o2 |= (unsigned char)FUN_0001ea64(DAT_002cfc8c, regs + 0x17a8, 0x20, 2, 9);
    *o3 |= (unsigned char)FUN_0001ea64(DAT_002cfc8c, regs + 0x17ac, 0x10, 2, 9);
    *o4 |= (unsigned char)FUN_0001ea64(DAT_002cfc8c, regs + 0x17b0, 0x40, 2, 9);
    *o5 = *o6 = *o7 = *o8 = 0;
    *o5 |= DAT_002cfc8c->status3 == 0;
    *o6 |= DAT_002cfc8c->status1 == 0;
    *o7 |= DAT_002cfc8c->status0 == 0;
    *o8 |= DAT_002cfc8c->status2 == 0;
}
