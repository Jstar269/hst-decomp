/* HSTMATCH module=hstp_trans_main.prx start=0x0014a96c end=0x0014a9dc symbol=__dt__10D_0014a96cFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0014a96c { int v; ~Elem_0014a96c() {} };
class V_0014a96c {
public:
    Elem_0014a96c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0014a96c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0014a96c : public V_0014a96c { public: ~D_0014a96c(); };
D_0014a96c::~D_0014a96c() { size = 0; }
