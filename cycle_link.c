/**
 * @file    cycle_link.c
 * @brief   Practise create link and try to find the link if has a cycle.
 * @author  H034115
 * @date    9/29/2012 5:40:21 PM
 */
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next_node;
};

int is_cycle(struct node *link_node)
{
    struct node *node1, *node2;
    node1=link_node;
    node2=link_node->next_node;
    while(node1!=NULL && node2!=NULL)
    {
        node1=node1->next_node;
        node2=node2->next_node;

       if(&node1==&node2)
        {
            return 0;
        }
    }
    return 1;
}

struct node *create_link()
{
    struct node *p1,*p2, *head;
    int number;
    head=NULL;
    while(1)
    {
        printf("%s","Please enter the data of node, enter -1 to exit:");
        scanf("%d",&number);
         if(number==-1)
        {
            break;
        }
        p2=p1;
        p1=(struct node*)malloc(sizeof(struct node));
        p1->data=number;
        if(head==NULL)
        {
            head=p1;
            p2=p1;
        }
        p1->next_node=NULL;
        p2->next_node=p1;
    }
    return head;
}

int main()
{
    struct node *create();
    int is_cycle(struct node *link_node);
    struct node *head, *p;
    head=NULL;
    head=create_link();
    p=head;
    while(p!=NULL)
    {
        printf("%d",p->data);
        printf("%s","\t");
        p=p->next_node;
    }

    int output;
    output=is_cycle(head);
    printf("%s","\n");
    printf("%d",output);

   return 0;
}
