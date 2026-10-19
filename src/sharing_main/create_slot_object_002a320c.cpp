/* HSTMATCH module=hstp_trans_main.prx start=0x002a320c end=0x002a32e8 symbol=FUN_002a320c lang=c++ */
/* Clone of src/eboot/create_slot_object_00291c00.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float DAT_003a89c8;
extern float DAT_003a89cc;
extern float DAT_003a89d0;
extern float DAT_003a89d4;
extern float DAT_003a89d8;
extern float DAT_003a89dc;
extern float DAT_003a89e0;

extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_000518d4(void *);
extern "C" void FUN_00051ad8(void *, void *, int);
extern "C" void FUN_00051d38(float, void *);

extern "C" void FUN_002a320c(char *o, int i) {
    if (*(void **)((i << 2) + (int)o + 0x18) != 0) return;
    float names[7];
    void *p;
    names[0] = DAT_003a89c8;
    names[1] = DAT_003a89cc;
    names[2] = DAT_003a89d0;
    names[3] = DAT_003a89d4;
    names[4] = DAT_003a89d8;
    names[5] = DAT_003a89dc;
    names[6] = DAT_003a89e0;
    p = FUN_00000bcc(0x48);
    if (p != 0) p = FUN_000518d4(p);
    *(void **)((i << 2) + (int)o + 0x18) = p;
    FUN_00051ad8(p, ((void **)names)[i], 0);
    FUN_00051d38(203010.0f, *(void **)((i << 2) + (int)o + 0x18));
}
