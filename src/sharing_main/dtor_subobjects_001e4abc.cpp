/* HSTMATCH module=hstp_trans_main.prx start=0x001e4abc end=0x001e4ba8 symbol=FUN_001e4abc lang=c++ */
/* Hand-written reconstruction (port of src/eboot/dtor_subobjects_001d6ccc.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Object reached through the DAT_003e1a08 handle; only a flag word is cleared. */
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

extern "C" char DAT_003eaad8[];
extern "C" char DAT_003b26b4[];
extern "C" char DAT_003b2680[];
extern "C" char DAT_003b264c[];
extern "C" void *DAT_003e1a08;

extern "C" Handle *FUN_0008f170(void *);
extern "C" void FUN_00108f54(void *, int);
extern "C" void FUN_00108dac(void *);
extern "C" void FUN_001c20b8(void *);
extern "C" void FUN_001087a8(void *, int);
extern "C" void FUN_0027cd7c(void *, int);
extern "C" void FUN_002b0294(void *, int);
extern "C" void FUN_00000a00(void *);

/* Deleting destructor: installs the vtable, resets the DAT_003e1a08 handle's object, destroys the embedded
   sub-objects (the one at +0x1110 through its inlined vtable chain), runs the base destructor and frees the
   object when flag > 0. */
extern "C" Owner *FUN_001e4abc(Owner *self, short flag) {
    Handle *handle;
    if (self != 0) {
        self->vtable = &DAT_003b26b4;
        handle = FUN_0008f170(DAT_003e1a08);
        FUN_00108f54(handle, 0);
        (*handle->ref)->unk64 = 0;
        FUN_00108dac(handle);
        FUN_001c20b8(DAT_003eaad8);
        void **slot = &self->subCVtable;
        if (slot != 0 && ((self->subCVtable = &DAT_003b2680), slot != 0)) {
            self->subCVtable = &DAT_003b264c;
            FUN_001087a8(slot, 0);
        }
        FUN_0027cd7c(self->subB, -1);
        FUN_002b0294(self->subA, -1);
        FUN_001087a8(self, 0);
        if (flag > 0) FUN_00000a00(self);
    }
    return self;
}
