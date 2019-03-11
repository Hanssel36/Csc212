#include"sequence3.h"
#include <cassert> 
#include <iostream>
#include <cstdlib> 
#include "node1.h"
using namespace std;

namespace main_savitch_5
{
	sequence::sequence( ){
		head_ptr = NULL;
		tail_ptr = NULL;
		many_nodes = 0;

	}

	 sequence::sequence(const sequence& source){

	 list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
 }
 	 sequence::~sequence( ){

 	 	list_clear(head_ptr);
 	 	many_nodes = 0;
 	 }

 	 void sequence::start( ){
 	 	current_index = 1;

 	 }

 	 void sequence::advance( ){
 	 	current_index++;
 	 }
 	 void sequence::remove_current( ){
 	 	if(is_item() == true){
 	 		if(current_index == 1){
 	 			list_head_remove(head_ptr);
 	 			--many_nodes;

 	 		}else{
 	 		cursor = head_ptr;
 	 		for (size_t i = 1; (i < current_index-1) && (cursor != NULL); i++){
	    cursor = cursor->link( );
	}

			list_remove(cursor);
			--many_nodes;
 	 	}
	 	
 	 			}
 	 }

 	 void sequence::attach(const value_type& entry){
 	 	if(size() > 0 && is_item() == true){
 	 		cursor = head_ptr;
	for (size_t i = 1; (i < current_index) && (cursor != NULL); i++){
	    cursor = cursor->link( );
	}
 	 		list_insert(cursor,entry);
 	 		++many_nodes;
 	 		current_index++;

 	 	}else if(size() > 0 && is_item() == false){
 	 		cursor = head_ptr;
 	 		for (size_t i = 1; (i < many_nodes ) && (cursor != NULL); i++){
	    cursor = cursor->link( );
	}
 	 		list_insert(cursor,entry);
 	 		++many_nodes;
 	 		current_index = many_nodes;
 	 	}else{
 	 		list_head_insert(head_ptr,entry);
 	 	++many_nodes;
 	 	current_index = 1;
 	 	}
 	 	

 	 }

 	 void sequence::insert(const value_type& entry){
 	 	if(size() > 0 && is_item() == true){
 	 		// Works like attach. Needs to change.
 	 		node *precursor;
 	 		precursor = NULL;
 	 	
 	 		for (size_t i = 1; (i < current_index-1) && (cursor != NULL); i++){
	    cursor = cursor->link( );
	}
 	 		list_insert(cursor,entry);
 	 		++many_nodes;
 	 		}
		}else if(size() > 0 && is_item() == false){
			list_head_insert(head_ptr, entry);
			current_index = 1;
			many_nodes++;

		}else{
			list_head_insert(head_ptr, entry);
			++many_nodes;
			current_index = 1;
		}

 	 }

	size_t sequence::size( ) const{

		return many_nodes;
	}

	void sequence::operator =(const sequence& source){
		list_clear(head_ptr);
		many_nodes = 0;
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
	}

	bool sequence::is_item( ) const{
			if(size() > 0 && current_index <= many_nodes){
				return true;

			}else{
				return false;
			}
		}
	sequence::value_type sequence::current( ) const{
		if(is_item() == true){
			node *k;
			k = list_locate(head_ptr, current_index);
	
			return k->data();

		}else{
			return false;
		}

	}
	

}