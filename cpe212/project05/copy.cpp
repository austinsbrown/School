template<typename ItemType>
void SmartHeap<ItemType>::Resize(int newsize)
{
  ItemType *tmp=new ItemType[newsize];
  for(int i=0; i<=num; i++)
    {
      tmp[i]=ptr[i];
    }
  delete ptr;
  ptr=tmp;
  maxsize=newsize;
}

//swap the data pointed to by given addresses                                                        
template<typename ItemType>
void SmartHeap<ItemType>::Swap(ItemType& a, ItemType& b)
{
  ItemType tmp=a;
  a=b;
  b=tmp;
}

//reconstruct heap order due to the deletion of the maximum (root) value                             
template<typename ItemType>
void SmartHeap<ItemType>::ReheapDown(int root, int bottom)
{
  int parent=root;
  int child=bottom;
  if(num > 1 && ptr[parent]>ptr[child])
    {
      Swap(ptr[parent], ptr[child]);
      ReheapDown(parent, (parent*2)+2);
    }

}

//reconstruct heap order when a child is greater than the parent                                     
template<typename ItemType>
void SmartHeap<ItemType>::ReheapUp(int root, int bottom)
{
  int parent=root;
  int child=bottom;
  if(num > 1 && ptr[parent]<ptr[child])
  {
    Swap(ptr[parent], ptr[child]);
    ReheapUp(parent/2, parent);
  }
}

template<typename ItemType>
void SmartHeap<ItemType>::Insert(ItemType n)
{
  if(num==maxsize )
    {
      Resize(2*maxsize);
    }
  ptr[num]=n;
  ReheapUp(num/2, num);
  num++;
}

//remove the root value and reconstruct heap order                                                   
template<typename ItemType>
ItemType SmartHeap<ItemType>::DeleteMax()
{
  if(IsEmpty())
    {
      throw EmptySmartHeap();
    }
  else
    {
      ItemType tmp=ptr[0];
      ptr[0]=ptr[num];
      num--;
      if(num<=(maxsize/2))
        {
          Resize(maxsize/2);
        }
      return tmp;
    }
}

//clears the heap of all inserted values                                                             
template<typename ItemType>
void SmartHeap<ItemType>::MakeEmpty()
{
  delete ptr;
  ptr=new ItemType[maxsize];
  num=0;
}

//return the number of items stored in the heap                                                      
template<typename ItemType>
int SmartHeap<ItemType>::Size() const
{
  return num;
}

template<typename ItemType>
void SmartHeap<ItemType>::MakeEmpty()
{
  delete ptr;
  ptr=new ItemType[maxsize];
  num=0;
}

//return the number of items stored in the heap                                                      
template<typename ItemType>
int SmartHeap<ItemType>::Size() const
{
  return num;
}

//return the current maximum size of the heap                                                        
template<typename ItemType>
int SmartHeap<ItemType>::Capacity() const
{
  return maxsize;
}