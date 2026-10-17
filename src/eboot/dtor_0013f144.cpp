/* HSTMATCH module=EBOOT.BIN start=0x0013f144 end=0x0013f1b0 symbol=__dt__10C_0013f144Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0013f1b0(void *self);
struct Blob_0013f144 { int v; ~Blob_0013f144() {} };
class B_0013f144 { public: Blob_0013f144 *data; ~B_0013f144() { FUN_0013f1b0(this); delete data; } };
class C_0013f144 : public B_0013f144 { public: int count; ~C_0013f144(); };
C_0013f144::~C_0013f144() { count = 0; }
