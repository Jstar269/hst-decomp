/* HSTMATCH module=EBOOT.BIN start=0x001e1ed8 end=0x001e1fb0 symbol=FUN_001e1ed8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" char DAT_002ebe48;
extern "C" char DAT_002ebc1c;
extern "C" char DAT_002c7db8;
extern "C" char DAT_002c7ec0;

extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" void FUN_00216e90(void *, void *, void *, int);
extern "C" void FUN_00216f14(void *, void *, void *, int);
extern "C" void FUN_002170ec(void *, void *, void *, int);
extern "C" void FUN_00217778(void *, void *);
extern "C" void FUN_00217704(void *, void *);

extern "C" void FUN_001e1ed8(char *o) {
    FUN_00104118(*(void **)(o + 0x1d68), &DAT_002ebe48, 0);
    FUN_00103540(*(void **)(o + 0x1d68), 2900.0f);
    FUN_001037c8(*(void **)(o + 0x1d68), -256);
    FUN_00216e90(o + 0x1d6c, *(void **)(o + 0x1d68), &DAT_002ebc1c, 5);
    FUN_00216f14(o + 0x1d80, o + 0x1d6c, &DAT_002c7db8, 8);
    FUN_002170ec(o + 0x1e20, o + 0x1d6c, &DAT_002c7ec0, 22);
    FUN_00217778(o + 0x1f28, *(void **)(o + 0x1d68));
    FUN_00217704(o + 0x1fb4, *(void **)(o + 0x1d6c));
    FUN_00217704(o + 0x2040, *(void **)(o + 0x1d70));
    FUN_00217704(o + 0x20cc, *(void **)(o + 0x1d74));
    FUN_00217704(o + 0x2158, *(void **)(o + 0x1d78));
}
