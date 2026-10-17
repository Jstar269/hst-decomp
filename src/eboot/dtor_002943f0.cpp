/* HSTMATCH module=EBOOT.BIN start=0x002943f0 end=0x0029445c symbol=__dt__10C_002943f0Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0029445c(void *self);
struct Blob_002943f0 { int v; ~Blob_002943f0() {} };
class B_002943f0 { public: Blob_002943f0 *data; ~B_002943f0() { FUN_0029445c(this); delete data; } };
class C_002943f0 : public B_002943f0 { public: int count; ~C_002943f0(); };
C_002943f0::~C_002943f0() { count = 0; }
