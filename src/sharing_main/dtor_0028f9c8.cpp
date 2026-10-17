/* HSTMATCH module=hstp_trans_main.prx start=0x0028f9c8 end=0x0028fa34 symbol=__dt__10C_0028f9c8Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0028fa34(void *self);
struct Blob_0028f9c8 { int v; ~Blob_0028f9c8() {} };
class B_0028f9c8 { public: Blob_0028f9c8 *data; ~B_0028f9c8() { FUN_0028fa34(this); delete data; } };
class C_0028f9c8 : public B_0028f9c8 { public: int count; ~C_0028f9c8(); };
C_0028f9c8::~C_0028f9c8() { count = 0; }
