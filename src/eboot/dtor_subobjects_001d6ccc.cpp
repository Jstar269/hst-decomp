/* HSTMATCH module=EBOOT.BIN start=0x001d6ccc end=0x001d6db8 symbol=FUN_001d6ccc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Object reached through the DAT_003386c8 handle; only a flag word is cleared. */
struct Inner { char pad00[100]; int unk64; };
struct Handle { char pad00[4]; Inner **ref; /* 0x04 */ };

/* Object with two embedded sub-objects and a third whose vtable is at +0x1110. */
struct Owner {
    void *vtable;                  /* 0x0000 */
    char pad04[0x290 - 4];
    char subA[0x530 - 0x290];      /* 0x0290 */
    char subB[0x1110 - 0x530];     /* 0x0530 */
    void *subCVtable;              /* 0x1110 */
};

extern "C" char DAT_0034179c[];
extern "C" char DAT_003093e8[];
extern "C" char DAT_003093b4[];
extern "C" char DAT_00309380[];
extern "C" void *DAT_003386c8;

extern "C" Handle *FUN_0008d994(void *);
extern "C" void FUN_00103628(void *, int);
extern "C" void FUN_00103480(void *);
extern "C" void FUN_001b3e2c(void *);
extern "C" void FUN_00102ea4(void *, int);
extern "C" void FUN_0026bda4(void *, int);
extern "C" void FUN_002a0e88(void *, int);
extern "C" void FUN_00000a00(void *);

/* Deleting destructor: installs the vtable, resets the DAT_003386c8 handle's object, destroys the embedded
   sub-objects (the one at +0x1110 through its inlined vtable chain), runs the base destructor and frees the
   object when flag > 0. */
extern "C" Owner *FUN_001d6ccc(Owner *self, short flag) {
    Handle *handle;
    if (self != 0) {
        self->vtable = &DAT_003093e8;
        handle = FUN_0008d994(DAT_003386c8);
        FUN_00103628(handle, 0);
        (*handle->ref)->unk64 = 0;
        FUN_00103480(handle);
        FUN_001b3e2c(DAT_0034179c);
        void **slot = &self->subCVtable;
        if (slot != 0 && ((self->subCVtable = &DAT_003093b4), slot != 0)) {
            self->subCVtable = &DAT_00309380;
            FUN_00102ea4(slot, 0);
        }
        FUN_0026bda4(self->subB, -1);
        FUN_002a0e88(self->subA, -1);
        FUN_00102ea4(self, 0);
        if (flag > 0) FUN_00000a00(self);
    }
    return self;
}
