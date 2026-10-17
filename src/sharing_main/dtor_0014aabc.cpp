/* HSTMATCH module=hstp_trans_main.prx start=0x0014aabc end=0x0014ab2c symbol=__dt__10D_0014aabcFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0014aabc { int v; ~Elem_0014aabc() {} };
class V_0014aabc {
public:
    Elem_0014aabc *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0014aabc() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0014aabc : public V_0014aabc { public: ~D_0014aabc(); };
D_0014aabc::~D_0014aabc() { size = 0; }
