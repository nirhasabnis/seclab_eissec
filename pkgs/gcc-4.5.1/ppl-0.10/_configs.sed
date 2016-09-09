s/#undef  *\([ABCDEFGHIJKLMNOPQRSTUVWXYZ_]\)/#undef PPL_\1/
s/#undef  *\([abcdefghijklmnopqrstuvwxyz]\)/#undef _ppl_\1/
s/#define  *\([ABCDEFGHIJKLMNOPQRSTUVWXYZ_][abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_]*\)\(.*\)/#ifndef PPL_\1 \
#define PPL_\1 \2 \
#endif/
s/#define  *\([abcdefghijklmnopqrstuvwxyz][abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_]*\)\(.*\)/#ifndef _ppl_\1 \
#define _ppl_\1 \2 \
#endif/
