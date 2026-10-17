/* HSTMATCH module=EBOOT.BIN start=0x0008e810 end=0x0008e984 symbol=FUN_0008e810 lang=c99 */
/* Clone of src/sharing_main/handle_event_00090254.c (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Event switch: events 0 and 1 do nothing; 4/6 and 8/0xe forward a mode to the helper at 0x903c8; 0xc also sets
   field +4 to 3; 0x12 resets the pool at +0x26c and clears three entries of the sub-object at +0x1e0; 0x18 grows
   the two pools to 600 and 2 when smaller and sets the same three entries. Cases are written in ascending
   order (the compiler tests them in reverse). Names provisional. */
typedef struct Pool_90254 {
    int a;
    int b;
    unsigned count;
} Pool_90254;
typedef struct Obj_90254 {
    char pad0[4];
    int mode;
    char pad1[0x1e0 - 8];
    char sub1e0[0x8c];
    Pool_90254 pool0;
    Pool_90254 pool1;
} Obj_90254;
extern void FUN_0001f20c();
extern void FUN_0008d9f8();
extern void FUN_0008e984();
extern void FUN_0009117c();

int FUN_0008e810(Obj_90254 *self, int ev)
{
    switch (ev) {
    case 0:
    case 1:
        break;
    case 4:
    case 6:
        FUN_0008e984(self, 5);
        break;
    case 8:
    case 0xe:
        FUN_0008e984(self, 1);
        break;
    case 0xc:
        FUN_0008e984(self, 5);
        self->mode = 3;
        break;
    case 0x12:
        FUN_0008d9f8(&self->pool0);
        FUN_0001f20c(self->sub1e0, 0, 0);
        FUN_0001f20c(self->sub1e0, 1, 0);
        FUN_0001f20c(self->sub1e0, 2, 0);
        break;
    case 0x18:
        if (self->pool0.count < 600)
            FUN_0009117c(&self->pool0, 600);
        if (self->pool1.count < 2)
            FUN_0009117c(&self->pool1, 2);
        FUN_0001f20c(self->sub1e0, 0, 1);
        FUN_0001f20c(self->sub1e0, 1, 1);
        FUN_0001f20c(self->sub1e0, 2, 1);
        break;
    }
    return 0;
}
