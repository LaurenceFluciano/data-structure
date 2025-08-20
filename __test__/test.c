#include "unity.h"
#include "stack.h"

void setUp(){};

void tearDown(){};

void test_push_single_element() {
    Stack stack;
    initStack(&stack);

    int data = 2;
    pushStack(&stack, &data, sizeof(data));

    TEST_ASSERT_EQUAL(data, *(int*)peekStack(&stack));
}

void test_push_multiple_elements() {
    Stack stack;
    initStack(&stack);

    int data1 = 2;
    int data2 = 3;

    pushStack(&stack, &data1, sizeof(data1));
    pushStack(&stack, &data2, sizeof(data2));

    TEST_ASSERT_EQUAL(data2, *(int*)peekStack(&stack));
}

static void describe_push_stack() {
    RUN_TEST(test_push_single_element);
    RUN_TEST(test_push_multiple_elements);
}

#define DESCRIBE(title) printf("\n[Describe] %s\n", title);
#define IT(title) printf("  [It] %s\n", title);


int main(void)
{
    UNITY_BEGIN();

    DESCRIBE("Stack push and peek");
        IT("should return the last pushed element");
        RUN_TEST(describe_push_stack);
    return UNITY_END();
}