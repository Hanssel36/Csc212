#include "sequence1.h"
using namespace main_savitch_3;
namespace main_savitch_3{

  sequence::sequence(){
    used = 0;
  }
  sequence::size_type sequence::size( ) const{
    return used;
    }
void sequence::insert(const value_type& entry){
  if(size() < CAPACITY){

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
  }

void sequence::start(){
  if(used > 0){
    current_index = 0;

    }

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
void sequence::advance( ){
  if(is_item() == true){

    current_index++;

    }
  }

void sequence::attach(const value_type& entry){
  if(size() < CAPACITY){
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
  }
bool sequence::is_item( ) const{
  if(size() > 0 && current_index < used){
    return true;
    }else{
      false;
      }

  }

sequence::value_type sequence::current( ) const{
  if(is_item() == true){
    return data[current_index];
  }else{
    return false;
    }
  }
