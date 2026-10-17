/* HSTMATCH module=EBOOT.BIN start=0x0014aba0 end=0x0014ac0c symbol=__dt__10C_0014aba0Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0014ac9c(void *self);
struct Blob_0014aba0 { int v; ~Blob_0014aba0() {} };
class B_0014aba0 { public: Blob_0014aba0 *data; ~B_0014aba0() { FUN_0014ac9c(this); delete data; } };
class C_0014aba0 : public B_0014aba0 { public: int count; ~C_0014aba0(); };
C_0014aba0::~C_0014aba0() { count = 0; }
