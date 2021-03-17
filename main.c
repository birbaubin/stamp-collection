#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stamp
{
    int price;
    int year;
    char * description;
};

struct album
{
    struct stamp** stamps;
    int size;
};

struct stamp * stamp_new(int price, int year, const char* desc);
void stamp_free(struct stamp* stamp);
void print_stamp(struct stamp stamp);
char* album_desc_max(struct album* album);


int main(){
   /* 
    struct stamp* one_stamp;
    one_stamp = stamp_new(100, 1998, "Holla seniorita");
    print_stamp(*one_stamp);
    stamp_free(one_stamp);
    */
    return 0;
   

}

/**** Creatre a new stamp ****/
struct stamp * stamp_new(int price, int year, const char* desc){

    struct stamp* one_stamp = malloc(sizeof(struct stamp));
    one_stamp->price = price;
    one_stamp->year = year;
    one_stamp->description = malloc(sizeof(desc));
    strcpy(one_stamp->description, desc);

    return one_stamp;
}


/**** Free a stamp ****/
void stamp_free(struct stamp* stamp){
    free(stamp->description);
    free(stamp);
    /* printf("Stamp freed"); */
}

/**** Print the details of a stamp ****/
void print_stamp(struct stamp stamp){
    printf("Stamp descripton : %s \n Year : %d\n Price : %d\n", stamp.description, stamp.year, stamp.price);
}

/**** Display description of the stamp with max price in an album ****/
char* album_desc_max(struct album* album){

    int index_max_price = 0;
    int max_price = album->stamps[0]->price;
    for (int i = 1; i < album->size; i++)
    {
        if(album->stamps[i]->price > max_price)
        {
            index_max_price = i;
            max_price = album->stamps[i]->price;
        }
    }

    return album->stamps[index_max_price]->description;
}


