#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct set
        {
        int n ;
        int *elements;
        };

void initSet(struct set *_set);

void inputSet(struct  set *_set);

bool checkElement(int element, struct set *_set);

void addElement(int element, struct set *_set);

void printSet(struct set _set);

void deleteElementSet(int element, struct set *_set);

void destroySet(struct set *_set);

void initTwoSets(struct set *s1, struct set *s2);


int main() {
    printf("Hello, World!\n");
    struct set _set1,s3,s4;
    initSet(&s3);
    initSet(&s4);
    initSet(&_set1);
    initTwoSets(&s3,&s4);
    inputSet((&_set1));
    printSet(_set1);
    deleteElementSet(2,&_set1);
    printSet(_set1);
    destroySet(&_set1);
    destroySet(&s3);
    destroySet(&s4);
    return 0;
}


void inputSet(struct set *_set)
{
    int n;
    printf("Введите количество элементов для ввода \n");
    scanf("%d",&n);

   // (*_set).elements = (int*)malloc(_set->n * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        int k;
        printf("Введите %d-ый элемент\n",i+1);
        scanf("%d",&k);
        addElement(k,_set);


    }
    printf("введено %d элементов\n", _set->n);


}

bool checkElement(int element, struct set *_set)
{
    for (int i = 0; i < _set->n; ++i)
    {
        if(_set->elements[i]==element)
            return false;
    }
    return true;
}

void addElement(int element, struct set *_set)
{
    if(_set->n == 0)
    {
        _set->elements = (int*)malloc(sizeof(int));
        _set->elements[0] = element;
        _set->n++;
    } else if (checkElement(element,_set))
    {
        int *tmpArr = (int*)malloc((_set->n+1)*sizeof(int));
        for (int i = 0; i < _set->n; ++i)
        {
            tmpArr[i] = _set->elements[i];
        }
        free(_set->elements);
        tmpArr[(_set->n)++]=element;
        _set->elements = tmpArr;
    }
}

void initSet(struct set *_set)
{
    _set->n = 0;
}



void printSet(struct set _set)
{
    printf("множество сожержит следующие элементы: \n");
    for (int i = 0; i < _set.n; ++i)
    {
        printf("%d ",_set.elements[i]);
    }
    printf("\n");
}

void deleteElementSet(int element, struct set *_set)
{
    if(_set->n == 0)
        return;
    if(!checkElement(element,_set))
    {
        int *tmpArr = (int*)malloc((_set->n-1)*sizeof(int));
        bool isDeleted = false;
        for (int i = 0; i < _set->n; ++i)
        {
            if(_set->elements[i]==element)
            {
                isDeleted = true;
                continue;
            }
            if(!isDeleted)
            {
                tmpArr[i] = _set->elements[i];
            } else
            {
                tmpArr[i-1] = _set->elements[i];
            }
        }
        free(_set->elements);
        if(_set->n-- != 0)
            _set->elements = tmpArr;
    }
}

void destroySet(struct set *_set)
{
    if(_set->n!=0)
        free(_set->elements);
    _set->n = 0;
}

void initTwoSets(struct set *s1, struct set *s2)
{
    printf("Введите первое множество\n");
    inputSet(s1);
    printf("Введите второе множество\n");
    inputSet(s2);
}