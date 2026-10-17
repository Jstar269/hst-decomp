/* HSTMATCH module=hstp_trans_main.prx start=0x0005c174 end=0x0005c1e4 symbol=__dt__10D_0005c174Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0005c174 { int v; ~Elem_0005c174() {} };
class V_0005c174 {
public:
    Elem_0005c174 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0005c174() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0005c174 : public V_0005c174 { public: ~D_0005c174(); };
D_0005c174::~D_0005c174() { size = 0; }
