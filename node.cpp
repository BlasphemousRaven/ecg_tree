#include "node.h"
#include <string>
#include <sstream>
#include <iostream>

int node::node_id = 0;

node::node(const std::string& name){
    if(name==""){
        
        std::stringstream stream;
        stream << node_id;
        std::string id = stream.str();

        std::string new_name = "node_" + id; 
        set_name(new_name);
        node_id++;
    }
    else{
        set_name(name);
    }
}

node::~node(){
    for(auto child:*children){
    
        delete child;
    }
    children->clear();
    nr_children = 0;
}

std::string node::get_name(){
    return this->name;
}

int node::get_nr_children(){
    return this->nr_children;
}

void node::set_name(std::string new_name){
    this->name = new_name;
}

void node::add_child(node* child){
    this->children->push_back(child);
    nr_children++;
}

node* node::get_child(int i){
    int len_children = this->children->size();

    //handle index out of range
    if (get_nr_children()<i) {return nullptr;}

    node* child = this->children->at(i);
    return child;

}