/* HSTMATCH module=EBOOT.BIN start=0x000b54ec end=0x000b5558 symbol=__dt__10C_000b54ecFv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000b5558(void *self);
struct Blob_000b54ec { int v; ~Blob_000b54ec() {} };
class B_000b54ec { public: Blob_000b54ec *data; ~B_000b54ec() { FUN_000b5558(this); delete data; } };
class C_000b54ec : public B_000b54ec { public: int count; ~C_000b54ec(); };
C_000b54ec::~C_000b54ec() { count = 0; }
