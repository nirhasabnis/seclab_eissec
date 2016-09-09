
/* 
 * EISSEC (Extracting Instruction Semantics via Symbolic Execution of Code
 * Generators) is a symbolic execution based system for automatically extracting
 * assembly to IR translators from code generators of modern compilers.
 * 
 * Copyright (C) 2012 - 2016 by Niranjan Hasabnis and R.Sekar in Secure Systems
 * Lab, Stony Brook University, Stony Brook, NY 11794.
 *
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or 
 * (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details. 
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */

#include <stdlib.h>
#include <stdio.h>

static int mysrandom_r(unsigned int seed, struct random_data *buf) {
   char *b = malloc(256);
   bzero(buf, sizeof(struct random_data));
   return initstate_r(seed, b, 256, buf);
}

static inline int myrandom(struct random_data *rd) {
   int32_t res;
   if (random_r(rd, &res)) {
      perror("random_r"); exit(1);
   }
   return res;
}

main(int argc, char *argv[]) {
   int seed = atoi(argv[1]);
   int mlen = atoi(argv[2]);
   float p = 1.0 - 1.0/mlen;
   int sum=0;
   struct random_data buf;
   mysrandom_r(seed, &buf);
   fprintf(stderr, "first random=%d\n", myrandom(&buf));
   for (int k=0; k < 1000; k++) {
      for (int i=0; i < 8; i++) {
         for (int j=0; j < 100000; j++) {
            int32_t res = myrandom(&buf);
            if ((((double)res)/RAND_MAX) > p) {
               //fprintf(stderr, "%d\t", j);
               sum += j;
               break;
            }
         }
      }
      //fprintf(stderr, "\n");
   }
   fprintf(stderr, "avg=%.1f\n", sum/8000.0);
}
