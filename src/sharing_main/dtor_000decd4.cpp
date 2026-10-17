/* HSTMATCH module=hstp_trans_main.prx start=0x000decd4 end=0x000ded40 symbol=__dt__10C_000decd4Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000ded40(void *self);
struct Blob_000decd4 { int v; ~Blob_000decd4() {} };
class B_000decd4 { public: Blob_000decd4 *data; ~B_000decd4() { FUN_000ded40(this); delete data; } };
class C_000decd4 : public B_000decd4 { public: int count; ~C_000decd4(); };
C_000decd4::~C_000decd4() { count = 0; }
