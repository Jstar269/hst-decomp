/* HSTMATCH module=hstp_trans_main.prx start=0x000f1c54 end=0x000f1cb8 symbol=FUN_000f1c54 lang=c++ */
/* Clone of src/eboot/member_array_delete_000ec664.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: walking base declared after the loop index, delete through a virtual-destructor class, member offset form kept as int arithmetic; exact match verified; names and types await human review. */
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_000f1c54(int param_1)
{
  int i = 0;
  int q = param_1;
  do {
    VC_0 *p = *(VC_0 **)(q + 0x40);
    if (p != 0) {
      delete p;
      *(VC_0 **)(q + 0x40) = 0;
    }
    i++;
    q += 4;
  } while (i < 6);
}
