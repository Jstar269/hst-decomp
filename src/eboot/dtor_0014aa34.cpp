/* HSTMATCH module=EBOOT.BIN start=0x0014aa34 end=0x0014aaa0 symbol=__dt__10C_0014aa34Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0014ace4(void *self);
struct Blob_0014aa34 { int v; ~Blob_0014aa34() {} };
class B_0014aa34 { public: Blob_0014aa34 *data; ~B_0014aa34() { FUN_0014ace4(this); delete data; } };
class C_0014aa34 : public B_0014aa34 { public: int count; ~C_0014aa34(); };
C_0014aa34::~C_0014aa34() { count = 0; }
