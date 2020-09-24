template<typename ItemType>
void SmartHeap<ItemType>::Resize(int newsize)
{
    if(newsize>4)
    {
        maxsize=newsize;
    }
    else
    {
        maxsize=4;
    }
    
    ItemType *tmp=new ItemType[maxsize];
    for(int i=0; i<=num; i++)
    {
      tmp[i] = ptr[i];
    }

    delete [] ptr;
    ptr=tmp;
}


template<typename ItemType>
void SmartHeap<ItemType>::Swap(ItemType& a, ItemType& b)
{
    ItemType temp = a;
    a = b;
    b = temp;
}


template<typename ItemType>
void SmartHeap<ItemType>::ReheapDown(int root, int bottom)
{
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root*2 +1;
    rightChild = root*2 + 2;

    if(leftChild <= bottom)
    {
        if(leftChild  == bottom)
        {
            maxChild = leftChild;
        }
        else
        {
            if(ptr[leftChild] <= ptr[rightChild])
            {
                maxChild = rightChild;
            }
            else
            {
                maxChild = leftChild;
            }
            
        }
        if(ptr[root] < ptr[maxChild])
        {
            Swap(ptr[root], ptr[maxChild]);
            ReheapDown(maxChild, bottom);
        }
    }
    
}


template<typename ItemType>
void SmartHeap<ItemType>::ReheapUp(int root, int bottom)
{
    int parent;
    if(bottom > root)
    {
        parent = (bottom-1) / 2;
        if(ptr[parent] < ptr[bottom])
        {
            Swap(ptr[parent], ptr[bottom]);
            ReheapUp(root, parent);
        }
    }
}


template<typename ItemType>
bool SmartHeap<ItemType>::IsFull() const
{
    return num == maxsize;
}


template <typename ItemType>
SmartHeap<ItemType>::SmartHeap()
{
    maxsize = DEFAULTSIZE;
    num = 0;
    ptr = new ItemType[maxsize];
}


template <typename ItemType>
SmartHeap<ItemType>::~SmartHeap()
{
    delete [] ptr;
    num = 0;
}


template <typename ItemType>
void SmartHeap<ItemType>::Insert(ItemType n)
{
    if(num==maxsize)
    {
        Resize(2*maxsize);
    }
    
    ptr[num]=n;
    ReheapUp(0, num);
    num++;
}


template <typename ItemType>
ItemType SmartHeap<ItemType>::DeleteMax()
{
    if(IsEmpty())
    {
      throw EmptySmartHeap();
    }
    
    else
    {
        ItemType temp = ptr[0];
        ptr[0] = ptr[num - 1];
        num--;

        if(num < (maxsize/2))
        {
            Resize(maxsize/2);
        }
        
        ReheapDown(0, num);
        return temp;
    }
}


template <typename ItemType>
void SmartHeap<ItemType>::MakeEmpty()  
{
    delete [] ptr;
    ptr=new ItemType[maxsize];
    num=0;
}                      
  

template <typename ItemType>
bool SmartHeap<ItemType>::IsEmpty() const
{
    return num == 0;
}


template <typename ItemType>
int SmartHeap<ItemType>::Size() const 
{
    return num;
}


template <typename ItemType>                    
int SmartHeap<ItemType>::Capacity() const   
{
    return maxsize;
} 