/* HSTMATCH module=EBOOT.BIN start=0x00293ae0 end=0x00293b7c symbol=FUN_00293ae0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor of an object holding Elem[8] (12-byte elements, sizes at +4): body shrinks each element by its own size through the out-of-line 0x294010 (empty tag by value), then the member-array destroy 0x788 with the element deleting-dtor stub 0x293a74. Names provisional. */
struct Tag {};
struct Elem {
    int a;
    int size;
    int c;
};
struct Obj {
    Elem e[8];
};
extern "C" void FUN_00294010(Elem *, int, Tag);
extern "C" void FUN_00293a74();
extern "C" void FUN_00000788(void *, void *, int, int);
extern "C" void FUN_00000a00(void *);

extern "C" Obj *FUN_00293ae0(Obj *self, short flag)
{
    if (self) {
        int i;
        for (i = 0; i < 8; i++) {
            FUN_00294010(&self->e[i], self->e[i].size, Tag());
        }
        FUN_00000788(self, (void *)FUN_00293a74, 12, 8);
        if (flag > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}
