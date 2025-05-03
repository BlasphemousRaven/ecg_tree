#include "node.h"
#include <iostream>
#include <string>
#include <sstream>
void create_tree_rec();

int main(){
    /*
    node* root = new node();
    node* right_child = new node("right_child");
    node* left_child = new node("left_child");
    
    root->add_child(right_child);
    root->add_child(left_child);

    std::cout<<root->get_name();
    std::cout<<right_child->get_name();
    std::cout<<left_child->get_name();
   

    //deletes children
    root->~node();
    int a = root->get_nr_children();
    //deletes node
    delete root; 
    */

    node* new_node = new node();
    node* new_node_2 = new node();
    std::cout<<new_node->get_name()<<std::endl;
    std::cout<<new_node_2->get_name()<<std::endl;




    return 0;
}
