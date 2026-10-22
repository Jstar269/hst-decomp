/* HSTMATCH module=EBOOT.BIN start=0x00050b2c end=0x00050bb8 symbol=FUN_00050b2c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Asks FUN_00039d5c for a mode and, when it is not zero, reports it with FUN_0004f010; then it clears
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
extern char DAT_00311170;
extern char DAT_002d0a6c;
extern char DAT_002d0d40;
int FUN_00039d5c(void);
void FUN_0004f010(char *a, int b, char *c, int d, char *e);
}

extern "C" void FUN_00050b2c(Obj *self)
{
    int v = FUN_00039d5c();
    if (v != 0) {
        FUN_0004f010(&DAT_00311170, v, &DAT_002d0a6c, 0x803, &DAT_002d0d40);
    }
    self->f0 = 0;
    self->f1 = 0;
    self->f2 = 0;
    self->f3 = 0;
    self->f4 = 0;
}
