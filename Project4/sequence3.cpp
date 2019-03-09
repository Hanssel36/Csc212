#include"sequence3.h"
#include <cassert> 
#include <cstdlib> 
#include "node1.h"
using namespace std;

namespace main_savitch_5
{
	sequence::sequence( ){
		head_ptr = NULL;
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
 	 	current_index;

 	 }

 	 void sequence::attach(const value_type& entry){
 	 	list_head_insert(head_ptr,entry);
 	 	++many_nodes;
 	 	current_index = 0;

 	 }

 	 void sequence::insert(const value_type& entry){
 	 	list_head_insert(head_ptr, entry);
		++many_nodes;
		current_index = 0;

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

}