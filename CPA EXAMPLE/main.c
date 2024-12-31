#include "include_h.h"

int main(){
    table t;
    parse("data.csv", &t);
    float count = 0;
    for(int i = 0; i < 3; i++){
        float temp_count = 0;
        for(int j = 0; j < t._list_credit[i].capacity; j++){
            temp_count += t._list_credit[i].list[j] * (4-i);
        }
        printf("Grade Point %d: %f\n", 4-i, temp_count);
        printf("CPA %d: %f\n", 4-i, temp_count/(t._list_credit[i].capacity * (4-i)));
        count += temp_count;
    }
    printf("All Grade Point: %f\n", count);
    printf("All CPA: %f\n", count/(t._list_credit[0].capacity * 4 + t._list_credit[1].capacity * 3 + t._list_credit[2].capacity *2));

    // free the memory
    for(int i = 0; i < 3; i++){
        free(t._list_credit[i].list);
    }

    return 0;
}