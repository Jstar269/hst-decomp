/* HSTMATCH module=EBOOT.BIN start=0x0013f000 end=0x0013f06c symbol=__dt__10C_0013f000Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0013f21c(void *self);
struct Blob_0013f000 { int v; ~Blob_0013f000() {} };
class B_0013f000 { public: Blob_0013f000 *data; ~B_0013f000() { FUN_0013f21c(this); delete data; } };
class C_0013f000 : public B_0013f000 { public: int count; ~C_0013f000(); };
C_0013f000::~C_0013f000() { count = 0; }
