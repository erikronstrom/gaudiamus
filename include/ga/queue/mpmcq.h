/*
  
  Copyright (c) 2017 Erik Ronström
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.

*/

#ifndef _GA_MPMCQ
#define _GA_MPMCQ

/*****************************************************************

                LOCK FREE BOUNDED MPSC FIFO QUEUE

  A lock free, bounded FIFO queue, for multiple producers and
  multiple consumers.

  No (heap) memory allocation is performed in the queue (after creation).



 *****************************************************************/

#include <stdlib.h>
#include <ga/util.h>
#include <ga/error.h>

/*
 *  TYPES
 */

typedef struct ga_mpmcq ga_mpmcq;

/*
 *  FUNCTIONS
 */

ga_mpmcq* ga_mpmcq_create(size_t capacity);
void ga_mpmcq_destroy(ga_mpmcq *queue);

bool ga_mpmcq_push(ga_mpmcq *queue, void *value);
void* ga_mpmcq_pop(ga_mpmcq *queue);
void* ga_mpmcq_peek(ga_mpmcq *queue);
void ga_mpmcq_clear(ga_mpmcq *queue);

void debug_mpmcq(ga_mpmcq *queue);

#endif
