#include "node.h"
#include <iostream>

int main(){

    //node* root = create_complete_tree(2,4);
    node* node_1 = new node();
    node* node_2 = new node();
    node* node_3 = new node();
    node* node_4 = new node();

    node_1->add_child(node_2);
    node_2->add_child(node_3);
    node_3->add_child(node_4);
    node_4->add_child(node_1);
    
    std::cout<<node_1;

    //std::cout<<node_1;
    return 0;
}
