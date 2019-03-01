#include "sequence2.h"
#include <algorithm>
using namespace std;

namespace main_savitch_4{
  sequence::sequence(size_type initial_capacity){
    data =  new value_type[initial_capacity];
    capacity = initial_capacity;
    used = 0;
    }
  sequence::sequence(const sequence& source){
    data = new value_type[source.capacity];
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
      resize(used+1);
      }
    if(is_item() == true){
      used++;
    for(int i = used; i > current_index; --i){

      data[i] = data[i-1];

      }
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
      resize(used+1);
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