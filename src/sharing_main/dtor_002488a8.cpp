/* HSTMATCH module=hstp_trans_main.prx start=0x002488a8 end=0x00248914 symbol=__dt__10C_002488a8Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00248a30(void *self);
struct Blob_002488a8 { int v; ~Blob_002488a8() {} };
class B_002488a8 { public: Blob_002488a8 *data; ~B_002488a8() { FUN_00248a30(this); delete data; } };
class C_002488a8 : public B_002488a8 { public: int count; ~C_002488a8(); };
C_002488a8::~C_002488a8() { count = 0; }
