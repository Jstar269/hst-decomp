/* HSTMATCH module=hstp_trans_main.prx start=0x0017c9bc end=0x0017ca98 symbol=FUN_0017c9bc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Two input-driven adjustments of the object at +0x178, selected by 2-bit signed fields of the config bytes at
   +0x88/+0x8c (LSB-first bitfields give retail's sll/sra pairs): FUN_0018a308 gets +/-f2bc (only when flag is 0;
   the value is read before the tests, as retail loads it into $f12 ahead of the first branch), FUN_0018a524 gets
   +/-f2b4 converted from degrees to radians and a third argument 1 (retail reuses the compare constant in a1). */
typedef struct Cfg {
    char pad[0x88];
    signed char a0 : 2;
    signed char a1 : 2;
    signed char a2 : 2;
    signed char a3 : 2;
    char pad89[3];
    signed char b0 : 2;
    signed char b1 : 2;
    signed char b2 : 2;
    signed char b3 : 2;
} Cfg;

typedef struct Obj {
    char pad0[0x178];
    void *target;
    char pad1[0x2b4 - 0x17c];
    float f2b4;
    float f2b8;
    float f2bc;
} Obj;

extern Cfg *DAT_003751d4;
extern void FUN_0018a308(void *obj, float d);
extern void FUN_0018a524(void *obj, float d, int flag);

void FUN_0017c9bc(Obj *self, int flag)
{
    float a;
    if (flag == 0) {
        float v = self->f2bc;
        if (DAT_003751d4->b0 == 1) FUN_0018a308(self->target, v);
        else if (DAT_003751d4->b2 == 1) FUN_0018a308(self->target, -v);
    }
    a = self->f2b4 * 0.017453292f;
    if (DAT_003751d4->a0 != 0) {
        if (DAT_003751d4->b3 == 1) FUN_0018a524(self->target, a, 1);
        else if (DAT_003751d4->b1 == 1) FUN_0018a524(self->target, -a, 1);
    }
}
