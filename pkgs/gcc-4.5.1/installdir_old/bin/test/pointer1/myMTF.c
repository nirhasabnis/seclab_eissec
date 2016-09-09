#include <unistd.h>
#include <stdio.h>

#define UChar unsigned char

int main()
{
						int i;
						UChar ll_i = 0xEA;
						UChar yy[256];

						for(i = 0; i < 256; i++);
								//yy[i] = (UChar) i;

            register UChar  rtmp;
            register UChar* ryy_j;
            rtmp  = yy[1];
            ryy_j = &(yy[1]);
            while ( rtmp != ll_i ) {
               register UChar rtmp2;
							 register UChar rtmp3;
               ryy_j++;
               rtmp2  = rtmp;
							 rtmp3 = (rtmp2 == 0xEE);

							 printf("%2x", yy[0]);
							 if(rtmp3) {
               rtmp   = *ryy_j;
							 *ryy_j = rtmp2;
							 }
						}
						yy[0] = rtmp;

						printf("%2x", yy[0]);

						return 0;
}
