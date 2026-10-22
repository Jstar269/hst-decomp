/* HSTMATCH module=hstp_trans_main.prx start=0x00002c3c end=0x00002c98 symbol=FUN_00002c3c lang=c++ */
/* Clone of src/eboot/init_object_00002c3c.cpp (hstclone.py tag om1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Creates an object: the base constructor runs first, then the vtable pointer at +0 is set to
   0x3b01e8 and the member at +0x0c is initialised with the two arguments; the object is returned.
   Matching idiom: the base constructor is declared with the object as its parameter so that MWCC
   keeps the argument register unchanged and only copies it into the saved register in the delay
   slot of the call, exactly as retail does. */
typedef struct {
    void *vptr;
    char pad[8];
    int f3;
} Obj;

extern "C" {
extern void *DAT_003b01e8;
void FUN_00002d1c(Obj *self);
void FUN_00002ce0(int *p, int a, int b);
}

extern "C" Obj *FUN_00002c3c(Obj *self, int a, int b)
{
    FUN_00002d1c(self);
    self->vptr = &DAT_003b01e8;
    FUN_00002ce0(&self->f3, a, b);
    return self;
}
