#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

using namespace std;

TEST_CASE("jumping algorithm") {
    SUBCASE("testing build") {
        struct node* linked_list = build_linked_list(25);
        struct node* array = array_ptrs_to_each_element_in_linked_list(linked_list, 25);
        for(int i = 0; i < 25; i++) {
            CHECK(array[i].number == i);
        }
    };

    SUBCASE("pushing pointers to next") {
        struct node* linked_list4 = build_linked_list(3);
        struct node* array4 = array_ptrs_to_each_element_in_linked_list(linked_list4, 3);
        change_pointers(array4, 3);
        CHECK(array4[0].next == array4[1].next);
        CHECK(array4[0].next == array4[2].next);

        struct node* linked_list5 = build_linked_list(20);
        struct node* array5 = array_ptrs_to_each_element_in_linked_list(linked_list5, 20);
        change_pointers(array5, 20);
        struct node* ptr = array5[0].next;
        for(int i = 0; i < 20; i++) {
            CHECK(array5[i].next == ptr);
        }
    };
}