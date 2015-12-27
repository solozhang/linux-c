#include "singlelist.h"
int main()
{
  Node<float> head(-1);
  float add[5] = {1,2,3,2,4};
  float del[5] = {1,2,3,2,4};
  for(int i = 0; i < 5; i++)
      head.add(head, add[i]);
  for(int i = 0; i < 5; i++)
      head.del(head, del[i]);
//  delete head;
  return 0;
}
