#ifndef NODE
#define NODE

typedef struct NODE_{
   int capacity;
   float* list;
}node;


typedef struct TABLE_{
    /*
        0 is credit 4
        1 is credit 3
        2 is credit 2
    */
    node _list_credit[3];
}table;

#endif