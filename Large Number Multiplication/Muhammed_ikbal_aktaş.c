#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	
	int num;
	struct Node* next;
	struct Node* before;
}node;
node* big_one;
node* small_one;
node* result;
node* final_result;
void add_two_nodes(node**result ,node**final_result);
void add(node** root,int number){
	//adds node to the end of linked list
	node* new_node=(node*) malloc(sizeof(node));
	new_node->num=number;
	new_node->next=NULL;
	node* iter=*root;
	if(*root==NULL){
		new_node->before=NULL;
		*root=new_node;
		
		return;
	}
	while(iter->next!=NULL){
		iter=iter->next;
	}
	iter->next=new_node;
	
	new_node->before=iter;
	return;
		
	
	
}
void add_first(node** root,int number){
	//adds node at the first index of linked list
	node* new_node=(node*)malloc(sizeof(node));
	new_node->num=number;
	new_node->before=NULL;
	if(*root==NULL){
		new_node->next=NULL;
		*root=new_node;
	}
	else{
		new_node->next=*root;
		(*root)->before=new_node;
		*root=new_node;
	}
	
}
node* go_first_index(node** root){
	//returns the address of first node in linked list
	return *root;
}
node* go_last_index(node** root){
	//returns the address of last index of node in linked list
	node* iter=*root;
	if(iter==NULL)return NULL;
	else{
		while(iter->next!=NULL)iter=iter->next;
	}
	return iter;
}


void multiply_node_by_number(node** root,node **result,node** final_result,int multiplier){
	//multiply each node member with the multiplier value and adds to final result
    node* iter=*root;
    node *iter2=*result;
    int elde=0;
    
    int new_number=0;
    int res=0;
    
    iter=go_last_index(root);
    iter2=go_last_index(result);
    
    while (iter!=NULL)
    {
        res=(iter->num*multiplier)+elde;
        new_number=(res%10);
        elde=res/10;
        
        if(iter2==NULL){
            add_first(result,new_number);
        }
        else{
            iter2->num=new_number;
            iter2=iter2->before;
            
            
        }
        iter=iter->before;
        

    }
    if(elde>0){
        add_first(result,elde);
    }
    add_two_nodes(result,final_result);
    

    
    

}

void add_two_nodes(node ** node1,node** node2){
	//adds two nodes 
    node* iter1=*node1;
    node* iter2=*node2;
    iter1=go_last_index(node1);
    
    iter2=go_last_index(node2);
    
    int elde=0;
    int result=0;
    while(iter1!=NULL){
        
        if(iter2==NULL){
            add_first(node2,0);
            iter2=go_first_index(node2);
        }
        result=iter1->num+iter2->num+elde;
        
        iter2->num=result%10;
        elde=result/10;
        iter1=iter1->before;
        iter2=iter2->before;

    }
    if(elde>0){
        add_first(node2,elde);
    }


}


void multiply_whole_node_numbers(node** big_one,node** small_one,node** result,node** final_result){
	//multiply all node element with each other
    node*iter_small=*small_one;
    iter_small=go_last_index(small_one);
    
    while(iter_small!=NULL){
        multiply_node_by_number(big_one,result,final_result,iter_small->num);
        
        iter_small=iter_small->before;
        add(big_one,0);
    }

}
int main(){
	FILE *output_file,*input_file;
    input_file=fopen("input.txt","r");
    output_file=fopen("output.txt","w");
	//opens two file one for reading and one for writing

    char ch;
    char *number1=(char*)malloc(1000*sizeof(char));
    char *number2=(char*)malloc(1000*sizeof(char));
    char *cp;
    cp=number1;
    int j=0;
    int i=0;
 	fprintf(output_file,"number1: ");
    while((ch = fgetc(input_file)) != EOF){
        //gets all characters inside txt file
        //and saves to two char array
        *cp=ch;
        cp++;
        if(ch=='\n'){
            
            cp=number2;
            fprintf(output_file,"%c",ch);
            fprintf(output_file,"number2: ");
            continue;
        };
        fprintf(output_file,"%c",ch);
        j++;
    };
     fprintf(output_file,"%c",'\n'); 
    
    cp=number1;
    int num=0;
    while((*cp)!='\n'){
        
        //adds numbers inside first char array to first linked list (big_one)
        add(&big_one,(*cp)-'0');
        
        cp++;
        i++;

    }
    cp=number2;
    j=j-i;
    i=0;
    while(i<j){
        //adds numbers inside second char array to second linked list (small_one)
        
        add(&small_one,(*cp)-'0');
        
        cp++;
        i++;

    }
    multiply_whole_node_numbers(&big_one,&small_one,&result,&final_result);
    
	node*iter=go_first_index(&final_result);
	fprintf(output_file,"result : ");
	while(iter!=NULL){
		//prints the numbers inside final_result to the txt output file
			fprintf(output_file,"%d",iter->num);
			iter=iter->next;
		}
	
	
	
	
	
	
	
	return 0;
}
