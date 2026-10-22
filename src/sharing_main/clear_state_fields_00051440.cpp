/* HSTMATCH module=hstp_trans_main.prx start=0x00051440 end=0x000514cc symbol=FUN_00051440 lang=c++ */
/* Clone of src/eboot/clear_state_fields_00050b2c.cpp (hstclone.py tag om1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Asks FUN_00039d84 for a mode and, when it is not zero, reports it with FUN_0004f864; then it clears
   the five counters at +0x1a00c of the object.
   Matching idiom: the counters are at +0x1a00c, so MWCC addresses them through the 0x20000 page
   with a negative displacement (lui 0x2 / addu / sw zero,-0x5ff4). */
typedef struct {
    char pad[0x1a00c];
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
} Obj;

extern "C" {
extern char DAT_003ba4b0;
extern char DAT_003763c8;
extern char DAT_003767fc;
int FUN_00039d84(void);
void FUN_0004f864(char *a, int b, char *c, int d, char *e);
}

extern "C" void FUN_00051440(Obj *self)
{
    int v = FUN_00039d84();
    if (v != 0) {
        FUN_0004f864(&DAT_003ba4b0, v, &DAT_003763c8, 0x803, &DAT_003767fc);
    }
    self->f0 = 0;
    self->f1 = 0;
    self->f2 = 0;
    self->f3 = 0;
    self->f4 = 0;
}
