s/#undef  *\([ABCDEFGHIJKLMNOPQRSTUVWXYZ_]\)/#undef PWL_\1/
s/#undef  *\([abcdefghijklmnopqrstuvwxyz]\)/#undef _pwl_\1/
s/#define  *\([ABCDEFGHIJKLMNOPQRSTUVWXYZ_][abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_]*\)\(.*\)/#ifndef PWL_\1 \
#define PWL_\1 \2 \
#endif/
s/#define  *\([abcdefghijklmnopqrstuvwxyz][abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_]*\)\(.*\)/#ifndef _pwl_\1 \
#define _pwl_\1 \2 \
#endif/
