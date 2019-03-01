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


  void sequence::attach(const value_type& entry){
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