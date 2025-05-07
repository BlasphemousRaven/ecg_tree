#include "node.h"
#include <ostream>
#include <set>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <stack>

int node::node_id = 1;

node::node(const std::string& name){
    if(name==""){
        //converts node id from int to str
        std::stringstream stream;
        stream << node_id;
        std::string id = stream.str();
        //sets  name to node and cur id
        std::string new_name = "node_" + id; 
        set_name(new_name);
        //increments global id
        node_id++;
    }
    else{
        //sets name to constructor parameter
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
    child->depth = this->depth+1;
}

node* node::get_child(int i){
    int len_children = this->children->size();

    //handle index out of range
    if (get_nr_children()<i) {return nullptr;}

    node* child = this->children->at(i);
    return child;

}

node* create_complete_tree(int nr_child_nodes, int tree_depth,int current_depth){
    if (tree_depth==0) {
        return nullptr;
    }

    node* root = new node();
    root->depth = current_depth;
    
    //for every child: create child and add to current root
    for(int i=0;i<nr_child_nodes;i++){
       //recursively assigns children 
        node* child = create_complete_tree(nr_child_nodes, tree_depth-1,current_depth+1);
        //if the child is not null it will be added to root
        if (child!=nullptr) {
            root->add_child(child);
        }
    }

    return root;
    
}

std::vector<node*>* node::get_children(){
    return this->children;
}

void node::print_rec(std::ostream& str,int depth,std::set<node*> visited){
    //creates indent depending depth
    for(int i=0;i<depth;i++){
        str<<"   ";
    }

    str<<this->get_name()<<std::endl;

    for(node* child: *this->get_children()){
        //if node has not been visited yet, it will be added to set
        //otherwise --> cycle
        if(visited.count(child)==0){
            visited.insert(child);
            child->print_rec(str,depth+1,visited);
        }
        else{
            str<<"cycle detected [  ";
            for(node* node:visited){
                
                str<<node->get_name()<<"  ";
            }
            str<<"]\n";
        }
    }
}

void node::print_it(std::ostream& str){
    std::stack<node*> nodes;
    
    nodes.push(this);
    
    while (nodes.size()!=0) {
        node* node = nodes.top();
        nodes.pop();
        for(auto child:*node->get_children()){
            nodes.push(child);
        }
        for(int i=0;i<node->depth;i++){
            str<<"   ";
        }
        str<<node->get_name()<<"\n";
    }

    for(auto node : detect_cycle(this)){
        str<<"CYCLE LIST";
        str<<node<<std::endl;
    }
}

//DFS for detecting cycle
std::set<node*> detect_cycle(node* root){
    std::stack<node*> nodes;
    nodes.push(root);
    std::set<node*> visited = {};

    while (nodes.size()>0) {
        node* cur_node = nodes.top();
        nodes.pop();

        if(visited.count(cur_node)>0){
            std::cout<<"CYCLE!";
            return visited;
        }
        for(auto child:*cur_node->get_children()){
            if(visited.count(child)>0)continue;
            nodes.push(child);
        }
        visited.insert(cur_node);
         
    }
    return {};
   
}

std::ostream& operator<<(std::ostream& os, node* node){
    node->print_it(os);
    return os;
}