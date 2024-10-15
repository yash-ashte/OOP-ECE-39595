#include "Object.h"

void bar (Object& ref, Object* ptr) {
   ref.attribute = 0;
   ptr->attribute = 0;
}

void foo(const Object& ref, const Object* ptr) {
  // Commented lines will lead to compilation error
   //ref.attribute = 0;
   //ptr->attribute = 0;    
   //bar(ref, ptr);
   //Object* ptr2 = ptr;
   //Object* ptr4 = &ref;

  //Code below works. You can bypass constness through tricks.
  //This is highly ugly, contrived and not recommended!.
    long ptrValue = (long) ptr;
    void* ptr5 = (void*) ptrValue;
   ((Object*) ptr5)-> attribute = 0;
}  

int main(void){
  Object obj(2);
  foo(obj, &obj);
}