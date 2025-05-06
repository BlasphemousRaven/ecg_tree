#include "node.h"
#include <iostream>

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

    //node* root = create_complete_tree(4,10);
    //std::cout<<root;

    node* node_1 = new node();
    node* node_2 = new node();
    node* node_3 = new node();
    
    node_1->add_child(node_2);
    node_2->add_child(node_3);
    node_3->add_child(node_1);



    return 0;
}
