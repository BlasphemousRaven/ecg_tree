#include "node.h"
#include <iostream>

int main(){
    
    node* root = new node();
    node* right_child = new node("right_child");
    node* left_child = new node("left_child");
    node* new_child = new node("idk");

    root->add_child(right_child);
    root->add_child(left_child);
    right_child->add_child(new_child);
    std::cout<<root;
    
    //deletes children
    //root->~node();
    //int a = root->get_nr_children();
    //deletes node
    delete root; 
    

    //node* root = create_complete_tree(2,4);
    //std::cout<<root;

    

    //std::cout<<node_1;
    return 0;
}
