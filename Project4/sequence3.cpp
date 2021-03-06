#include <cassert>
#include"sequence3.h"
#include <iostream>
#include <cstdlib>
#include "node1.h"
using namespace std;
/*1. The items in the sequence are stored in a linked list.
2. The head pointer of the list is stored in the member variable head_ptr.
3. The Tail pointer of the list is stored in the member variable tail_ptr.
4. The total number of items in the list is stored in the member variable many_nodes.
5. Cursor points to the node with the current item (or NULL if there is no current item).
6. Precursor points to the node before current item (or NULL if there is no
current item or if the current item is the first node).
*/

namespace main_savitch_5
{

    sequence::sequence( ){
			//linked list O(1)
				//Dynamic O(1)
        head_ptr = NULL;
        tail_ptr = NULL;
		cursor = NULL;
		precursor = NULL;
        many_nodes = 0;

    }

     sequence::sequence(const sequence& source){
     	//linked list O(n)
			//Dynamic O(n)
			 if(source.cursor == NULL){
				 list_copy(source.head_ptr,head_ptr,tail_ptr);
				 cursor = NULL;
				 precursor =NULL;

				 }else if(source.head_ptr == source.cursor){
					 list_copy(source.head_ptr,head_ptr,tail_ptr);
					 cursor = head_ptr;
					 precursor = NULL;

					 }else{
						 list_copy(source.head_ptr,head_ptr,tail_ptr);
						 size_t p = 1;
						 for(node *Ncursor = source.head_ptr;Ncursor != source.precursor;Ncursor = Ncursor ->link()){
						 p++;
						 }
						 precursor = list_locate(head_ptr,p);
						 cursor = precursor->link();

					 }
					many_nodes = source.many_nodes;

}
      sequence::~sequence( ){
      	//linked list O(n)
			//Dynamic O(n)
          list_clear(head_ptr);
          many_nodes = 0;
      }

      void sequence::start( ){
      	//linked list O(1)
			//Dynamic O(1)
          cursor = head_ptr;
          precursor = NULL;
      }

      void sequence::advance( ){
      	//linked list O(1)
			//Dynamic O(1)
					if(is_item() == true){
					if(cursor->link() == NULL){
					precursor = NULL;
          cursor = NULL;

					}else{
						precursor = cursor;
						cursor = cursor ->link();
						}
					}
      }
void sequence::remove_current( ){
	//linked list O(1)
			//Dynamic O(n)
          if(is_item() == true){
              if(cursor->link() == NULL && head_ptr == cursor){
                  list_clear(head_ptr);

							precursor = NULL;
							cursor = NULL;

					}else if(cursor == head_ptr && cursor->link() != NULL){


							list_head_remove(head_ptr);
							cursor = head_ptr;
							precursor = NULL;

        }else{
						list_remove(precursor);
					cursor = precursor->link();
						}
						
          }
          		--many_nodes;
                  }


      void sequence::attach(const value_type& entry){
				//linked list O(1)
				//Dynamic O(n)
          if(size() > 0 && is_item() == true){

              list_insert(cursor,entry);
						precursor = cursor;
              cursor = cursor->link();
              ++many_nodes;
						tail_ptr = list_locate(head_ptr,many_nodes);
          }else if(size() > 0 && is_item() == false){
              cursor = tail_ptr;
              list_insert(cursor,entry);
							precursor = cursor;
              cursor= cursor->link();
              ++many_nodes;
								tail_ptr = list_locate(head_ptr,many_nodes);
          }else{
              list_head_insert(head_ptr,entry);
          ++many_nodes;
          cursor = head_ptr;
					precursor = NULL;
					tail_ptr = list_locate(head_ptr,many_nodes);
          }


      }

      void sequence::insert(const value_type& entry){
						//linked list O(1)
				//Dynamic O(n)
          if(size() > 0 && is_item() == true){
              if(cursor == head_ptr){
                  list_head_insert(head_ptr,entry);
                  cursor = head_ptr;
									precursor = NULL;

                  ++many_nodes;
								tail_ptr = list_locate(head_ptr,many_nodes);
              }else{
              list_insert(precursor,entry);
              cursor = precursor->link();
              ++many_nodes;
		tail_ptr = list_locate(head_ptr,many_nodes);
          }
        }else{
            list_head_insert(head_ptr, entry);
            ++many_nodes;
					tail_ptr = list_locate(head_ptr,many_nodes);
            cursor = head_ptr;
						precursor = NULL;
        }
    }






    size_t sequence::size( ) const{
    	//linked list O(1)
			//Dynamic O(1)

        return many_nodes;
    }

    void sequence::operator =(const sequence& source){
			//linked list O(n)
				//Dynamic O(n)
        if(this == &source){
            return;
        }
				list_clear(head_ptr);
				
         if(source.cursor == NULL){
				 list_copy(source.head_ptr,head_ptr,tail_ptr);
				 cursor = NULL;
				 precursor =NULL;
					

				 }else if(source.head_ptr == source.cursor){
					 list_copy(source.head_ptr,head_ptr,tail_ptr);
					 cursor = head_ptr;
					 precursor = NULL;
					

					 }else{
						 list_copy(source.head_ptr,head_ptr,tail_ptr);
						 size_t p = 1;
					 
					 for(node *Ncursor = source.head_ptr;Ncursor != source.precursor;Ncursor = Ncursor ->link()){
						 p++;
						 }

						 precursor = list_locate(head_ptr,p);
						 cursor = precursor->link();
							


					 }

					 many_nodes = source.many_nodes;
    }

    bool sequence::is_item( ) const{
						//linked list O(1)
				//Dynamic O(1)
            if(size() > 0 && cursor != NULL){
                return true;
            }else{
                return false;
            }
        }

    sequence::value_type sequence::current( ) const{
			//linked list O(1)
				//Dynamic O(1)
        if(is_item() == true){
            return cursor->data();
        }else{
            return false;
        }

    }


}
