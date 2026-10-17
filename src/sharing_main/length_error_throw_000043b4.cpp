/* HSTMATCH module=hstp_trans_main.prx start=0x000043b4 end=0x00004400 symbol=FUN_000043b4 lang=c++ data=0x003746e4 */
/* Hand-written reconstruction from the disassembly: `throw std::length_error(msg)` (constructor 0x3ab0, deleting destructor 0x39e8 and the runtime throw 0x260c are named through symbols/hstp_trans_main.prx.txt; the generated type-name string at 0x3746e4 is placed with data=; the two members of logic_error give the 12-byte exception object at s8+20); exact match verified; names and types await human review. */
namespace std {
class exception { public: exception(); virtual ~exception(); };
class logic_error : public exception { public: logic_error(const char *); virtual ~logic_error(); private: int pad[2]; };
class length_error : public logic_error { public: length_error(const char *); virtual ~length_error(); };
}
extern char DAT_003747b4[];
extern "C" void FUN_000043b4(void)
{
  throw std::length_error(DAT_003747b4);
}
