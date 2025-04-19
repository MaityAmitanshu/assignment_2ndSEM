#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node *link ;
} ;

struct node *insertAtend(struct node *ptr , int data) ;
struct node *insertAtbegin(struct node *ptr , int data) ;
struct node *insertAtindex(struct node *ptr , int index , int data) ;
struct node *deleteFROMbegin(struct node *ptr) ;
struct node *deleteFROMend(struct node *ptr) ;
struct node *deleteFROMindex(struct node *ptr,int index) ;                      
struct node *delete_LL(struct node *ptr) ;
struct node *creatnode(struct node *ptr , int data) ;
void traverse(struct node *ptr);

struct node *creatnode(struct node *ptr , int data) {
    ptr = (struct node*)malloc(sizeof(struct node)) ;
    ptr -> data = data ;
    ptr -> link = NULL ;
    return ptr ;
}

struct node *insertAtend(struct node *ptr , int data) {
    if ( ptr == NULL)
    {
        ptr = creatnode(ptr,data) ;
        return ptr ;
    }
    else
    {
        struct node *tmp = (struct node*)malloc(sizeof(struct node)) ;
        tmp -> data = data ;
        tmp -> link = NULL ;
        struct node *p = ptr ;
        while(p->link != NULL)
        {
            p = p-> link ;
        }
        p -> link = tmp ;
        return ptr ;
    }
}


struct node *insertAtbegin(struct node *ptr , int data) {
    if ( ptr == NULL)
    {
        ptr = creatnode(ptr,data) ;
        return ptr ;
    }
    else
    {
        struct node *tmp = (struct node*)malloc(sizeof(struct node)) ;
        tmp -> data = data ;
        tmp -> link = ptr ;
        return tmp ;
    }
}

struct node *insertAtindex(struct node *ptr , int index , int data) {
    struct node *trav = ptr ;
    struct node *tmp = (struct node*)malloc(sizeof(struct node)) ;
    tmp -> data = data ;
    if ( ptr == NULL)
    {
        ptr = creatnode(ptr,data) ;
        return ptr ;
    }
    else
    {
        int i = 0;
        while ( i != index-1)
        {
            trav = trav -> link ;
            i++ ;
        }

     tmp -> link = trav -> link ;
        trav -> link = tmp ;
        return ptr ;
    }
}

struct node *deleteFROMbegin(struct node *ptr) {
    if ( ptr == NULL)
    {
        printf("NOTHING TO DELETE !!") ;
        return ptr ;
    }
    else if (ptr->link == NULL)
    {
       free(ptr) ;
        return NULL ;
    }
    else
    {
        struct node *tmp = ptr ;
        ptr = ptr->link ;
        free(tmp) ;
        return ptr ;
    }
}

struct node *deleteFROMend(struct node *ptr) {
    struct node *p = ptr ;
    if ( ptr == NULL)
    {
        printf("NOTHING TO DELETE !!") ;
        return ptr ;
    }
    else if (ptr->link == NULL)
    {
       free(ptr) ;
        return NULL ;
    }
    else
    while (p->link->link != NULL)
    {
        p = p -> link ;
    }
    struct node *tmp = p -> link ;
    p -> link = NULL ;
    free(tmp) ;
    return ptr ;

}

struct node *deleteFROMindex(struct node *ptr,int index) {
    struct node *trav = ptr ;
    if ( ptr == NULL)
    {
        printf("NOTHING TO DELETE !!") ;
        return ptr ;
    }
    else
    {
        int i = 0;
        while ( i != index-1)
        {
            trav = trav -> link ;
            i++ ;
        }

       struct node *p = trav -> link ;
       trav->link = trav -> link -> link ;
       free(p) ;

        return ptr ;
    }

}

struct node *delete_LL(struct node *ptr) {
    struct node *p = ptr;
    while (p != NULL) {
        struct node *tmp = p;
        p = p->link;
        free(tmp);
    }
    return NULL;
}

void traverse(struct node *ptr) {
    struct node *p = ptr ;
    if (ptr == NULL)
    {
        printf("empty linked list \n") ;
    }
    else
    {
        printf("elements are \n") ;
        while (p != NULL)
        {
            printf("%d--->",p->data) ;
            p = p->link ;
        }
        printf("\n") ;
    }
}

int main () {
    struct node *head = NULL ;
    int a , data , pos;
    while(1)
    {
    printf("here is your menu ---> \n") ;
    printf("1 for insert at end \n ") ;
    printf("2 for insert at begin \n ") ;
    printf("3 for insert at index \n ") ;
    printf("4 for delete from begin \n ") ;
    printf("5 for delete from end \n ") ;
    printf("6 for delete from any index \n ") ;
    printf("7 for delete linked list full \n ") ;
    printf("8 for print the linked list \n") ;
    printf("9 for exit \n") ;
    printf("enter choice : ") ;

    scanf("%d",&a) ;

    switch(a)
    {
        case 1:
        printf("enter data to add : ") ;
        scanf("%d",&data) ;
       head = insertAtend(head,data) ;
       break ;

       case 2:
       printf("enter data to add : ") ;
        scanf("%d",&data) ;
            head = insertAtbegin(head,data) ;
            break ;

        case 3:
        printf("enter data to add : ") ;
        scanf("%d",&data) ;
        printf("enter position to add : ") ;
        scanf("%d",&pos) ;
       head = insertAtindex(head,pos,data) ;
        break ;

       case 4:
       head = deleteFROMbegin(head) ;
       break ;

       case 5:
       head = deleteFROMend(head) ;
        break ;

       case 6:
       printf("enter position to delete : ") ;
       scanf("%d",&pos) ;
       head = deleteFROMindex(head , pos) ;
       break ;

       case 7:
       head = delete_LL(head) ;
       break ;

       case 8:
       traverse(head) ;
       break ;

       case 9:
       return 0;

       default:
       printf("wrong choice !!") ;


    }



}

return 0;
}
