#include "sequence2.h"
#include <algorithm>
using namespace std;
//Invariant for the sequence class
/*1. The number of items in the sequence is in the member variable
used.
2. The actual items of the sequence are stored in a partially filled
array. The array is a dynamic array, pointed to by the
member variable data.
3. The total size of the dynamic array is in the member vari-
able capacity.
4. If there is a current item, then it lies in data[current_index]; if there is
no current item, then current_index equals used*/

namespace main_savitch_4{
  const sequence::size_type sequence::DEFAULT_CAPACITY;
  sequence::sequence(size_type initial_capacity){
    data =  new value_type[initial_capacity];
    capacity = initial_capacity;
    used = 0;
    }


  sequence::sequence(const sequence& source){
    data = new value_type[source.capacity];
    current_index = source.current_index;
    capacity = source.capacity;
    used = source.used;
    copy(source.data,source.data+used,data);
    }


  sequence::~sequence( ){
  delete [] data;
  }





  void sequence::resize(size_type new_capacity){
    value_type *larger_array;
    if(new_capacity == capacity){
      return;
      }
    if(new_capacity < used){
      new_capacity = used;
      }else{
    larger_array = new value_type[new_capacity];
    copy(data,data+used,larger_array);
    delete[] data;
    data = larger_array;
      capacity = new_capacity;
      }
    }
     sequence::value_type sequence::operator[](size_type index) const{
       if(index < used){
        return data[index];
       }
       }
    void sequence::operator+=(const sequence& sum){
      if(used + sum.used > capacity){
        resize(used+ sum.used);
        }
        copy(sum.data,sum.data + sum.used, data + used);
        used += sum.used;
      }
    sequence operator+(const sequence& s1, const sequence& s2){
      sequence total(s1.size()+s2.size());
      total += s1;
      total += s2;
      return total;
      }

    void sequence::operator=(const sequence& source){
      value_type *new_data;
      if(this == &source){
        return;
        }
      if(capacity != source.capacity){
        new_data = new value_type[source.capacity];
        delete [] data;
        data = new_data;
        capacity = source.capacity;
        current_index = source.current_index;
        }
      used = source.used;
      copy(source.data,source.data+used,data);

      }
   void sequence::start( ){
     if(used > 0){
    current_index = 0;

    }

     }
  void sequence::advance( ){
    if(is_item() == true){

    current_index++;

    }
    }
void sequence::remove_current( ){
  if(is_item() == true){
    for(int i = current_index; i <used; ++i){
      data[i] = data[i+1];
      }
      used--;
    }
  }
  void sequence::attach(const value_type& entry){
    if(used == capacity){
      resize(capacity+(capacity*.1));
      }
    if(is_item() == true){
    for(int i = used; i > current_index; --i){
      data[i] = data[i-1];
      }
      used++;
    current_index++;
      data[current_index] = entry;
    }else if(is_item() == false && size() > 0){
      data[used] = entry;
      used++;
      current_index = used;
  }else{
      data[0] = entry;
      used++;
      current_index = 0;
      }
  }


  void sequence::insert(const value_type& entry){
    if(used == capacity){
      resize(capacity+(capacity*.1));
    }
    if(is_item() == true){
    for(int i = used; i > current_index; --i){
      data[i] = data[i-1];
      }
      data[current_index] = entry;
      used++;
    }else if(is_item() == false && size() > 0){

      for(int i = used; i > 0; --i){
      data[i] = data[i-1];
      }
      used++;
      data[0] = entry;
      current_index = 0;
      }else{
        data[0] = entry;
      used++;
      current_index = 0;
        }
    }



sequence::size_type sequence::size( ) const{
    return used;
    }

bool sequence::is_item( ) const{
  if(size() > 0 && current_index < used){
    return true;
    }else{
      return false;
      }
  }
sequence::value_type sequence::current( ) const{
  if(is_item() == true){
    return data[current_index];
  }else{
    return false;
    }
  }
  }
