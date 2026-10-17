/* HSTMATCH module=EBOOT.BIN start=0x0014ac0c end=0x0014ac78 symbol=__dt__10C_0014ac0cFv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0014ac78(void *self);
struct Blob_0014ac0c { int v; ~Blob_0014ac0c() {} };
class B_0014ac0c { public: Blob_0014ac0c *data; ~B_0014ac0c() { FUN_0014ac78(this); delete data; } };
class C_0014ac0c : public B_0014ac0c { public: int count; ~C_0014ac0c(); };
C_0014ac0c::~C_0014ac0c() { count = 0; }
