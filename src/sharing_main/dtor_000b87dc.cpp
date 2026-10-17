/* HSTMATCH module=hstp_trans_main.prx start=0x000b87dc end=0x000b8848 symbol=__dt__10C_000b87dcFv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000b8848(void *self);
struct Blob_000b87dc { int v; ~Blob_000b87dc() {} };
class B_000b87dc { public: Blob_000b87dc *data; ~B_000b87dc() { FUN_000b8848(this); delete data; } };
class C_000b87dc : public B_000b87dc { public: int count; ~C_000b87dc(); };
C_000b87dc::~C_000b87dc() { count = 0; }
