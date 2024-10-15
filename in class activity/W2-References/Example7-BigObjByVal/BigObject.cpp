#include "BigObject.h"

BigObject::BigObject( ) {
   for (int i = 0; i < 100000; i++) {
      array[i] = i;
   }
}